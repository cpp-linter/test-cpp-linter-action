"""Run a command, sample its own peak RSS (VmHWM), print 'peak_mib=N' to stderr."""
import subprocess, sys, time
log = open(sys.argv[1], "w")
p = subprocess.Popen(sys.argv[2:], stdout=log, stderr=subprocess.STDOUT)
hwm = 0
while True:
    try:
        with open(f"/proc/{p.pid}/status") as f:
            for line in f:
                if line.startswith("VmHWM:"):
                    hwm = max(hwm, int(line.split()[1]))
    except OSError:
        pass
    if p.poll() is not None:
        break
    time.sleep(0.02)
print(f"peak_mib={hwm/1024:.0f} exit={p.returncode}", file=sys.stderr)
