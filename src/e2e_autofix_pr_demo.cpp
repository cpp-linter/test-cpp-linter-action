// Deliberately malformed fixture for the auto-fix e2e test.
//
// Two properties matter here:
//   1. clang-format has plenty to fix, so auto-fix has something to commit.
//   2. Formatting it changes its line count (the one-liners below expand),
//      which is what makes it able to catch clang-tidy diagnostics drifting
//      off the diff when the tools run in the wrong order.
int accumulate()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    return a + b + c + d + e;
}

int magic_user()
{
    int v = 42;
    return v;
}

int* null_user()
{
    int* p = 0;
    return p;
}
