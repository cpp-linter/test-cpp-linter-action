/** This is a very ugly test code (doomed to fail linting) */
#include "demo.hpp"
#include <cstdio>
#include <cstddef>

// using size_t from cstddef
size_t dummyFunc(size_t i) { return i; }

namespace {
bool hasName(const char* name)
{
    return  name;
}
} // namespace

int main()
{
    for (;;)
        break;

    printf("Hello world!\n");

    return hasName("demo") ? 0 : 42;
}
