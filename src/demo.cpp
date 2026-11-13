/** This is a very ugly test code (doomed to fail linting) */
#include "demo.hpp"
#include <cstddef>
#include <cstdio>

// using size_t from cstddef
size_t dummyFunc(size_t i) { return i; }

int main()
{
    for (;;)
        break;

    printf("Hello world!\n");

    return 0;
}
