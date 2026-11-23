#!/usr/bin/env bash
# Usage: bench.sh V1_BIN V2_BIN HYPERFINE LIBGIT2_DIR OUT_DIR
# Same setup as cpp-linter-rs#476: libgit2 v1.8.1, 133 .c files under src/libgit2, clang 18.
set -u
V1=$1; V2=$2; HF=$3; SRC=$4; OUT=$5; HERE=$(cd "$(dirname "$0")" && pwd)
mkdir -p "$OUT"; cd "$SRC"; unset GITHUB_TOKEN GITHUB_ACTIONS CI
ARGS="-l 0 -f 0 -a 0 -i=|!src/libgit2 -p build -e c -V 18"
FMT="--tidy-checks=-*"
hf() { name=$1; shift; "$HF" -N --style basic --export-json "$OUT/$name.json" --export-markdown "$OUT/$name.md" "$@" > "$OUT/$name.log" 2>&1; }
hf startup --warmup 3 --runs 20 -n v1 "$V1 version" -n v2 "$V2 version"
hf format-1 --warmup 1 --runs 5 -n v1 "$V1 $ARGS $FMT -j 1" -n v2 "env TOKIO_WORKER_THREADS=1 $V2 $ARGS $FMT"
hf format-all --warmup 1 --runs 5 -n v1 "$V1 $ARGS $FMT -j 0" -n v2 "$V2 $ARGS $FMT"
# One run each to check that both report the same counts, and to sample peak memory.
python3 "$HERE/mem.py" "$OUT/full-v1.out" $V1 $ARGS -j 0 2> "$OUT/mem-v1.txt"
python3 "$HERE/mem.py" "$OUT/full-v2.out" $V2 $ARGS 2> "$OUT/mem-v2.txt"
hf full-all --runs 3 -n v1 "$V1 $ARGS -j 0" -n v2 "$V2 $ARGS"
hf full-1 --runs 2 -n v1 "$V1 $ARGS -j 1" -n v2 "env TOKIO_WORKER_THREADS=1 $V2 $ARGS"
echo DONE > "$OUT/DONE"
