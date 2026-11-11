/** This is a very ugly test code (doomed to fail linting) */
#include "demo.hpp"
#include <cstdio>
#include <cstddef>

// using size_t from cstddef
size_t dummyFunc(size_t i) { return i; }

int scale(int value)
{
    if (value > 0)
        return value*3;
    return 0;
}

int main()
{
    for (;;)
        break;

    printf("Hello world! %d\n", scale( 14 ));

    return 0;
}
