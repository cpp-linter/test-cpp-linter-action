# C/C++ Lint Action Test Repository

[![cpp-linter as action](https://github.com/cpp-linter/test-cpp-linter-action/actions/workflows/cpp-lint-action.yml/badge.svg)](https://github.com/cpp-linter/test-cpp-linter-action/actions/workflows/cpp-lint-action.yml) 
<!-- [![cpp-linter as pkg](https://github.com/cpp-linter/test-cpp-linter-action/actions/workflows/cpp-lint-package.yml/badge.svg)](https://github.com/cpp-linter/test-cpp-linter-action/actions/workflows/cpp-lint-package.yml) -->

This is a test repository which has added `cpp-linter.yml`, so when an unformatted c/c++ source file was committed and create a Pull Request will automatically recognize and add warning comments.

If you have any suggestions or contributions, welcome to create issues/PRs [here](https://github.com/cpp-linter/cpp-linter-action).

## End-to-end test on a real pull request

The [`e2e on a real PR`](https://github.com/cpp-linter/test-cpp-linter-action/actions/workflows/e2e-pr.yml)
workflow tests a branch, tag or commit of cpp-linter-action on a real pull request in this repository:

1. Start the workflow with "Run workflow" and enter the action ref (for example `main` or `v3.0.0-rc0`)
   and the clang version.
2. It creates a branch `e2e/run-<id>` with known lint problems and opens a PR for it.
3. The PR runs the action on Linux, macOS and Windows, then checks the thread comment, the PR
   review, the file annotations and the outputs, and posts the result as a PR comment.
4. If everything passed, the PR is closed and its branch deleted. If not, it stays open for a look.

GitHub does not start workflows for a PR that was opened with the default token. Until a
repository secret named `E2E_TOKEN` exists (a token that may push branches and open PRs here),
close and reopen the PR from step 2 to start the test.
