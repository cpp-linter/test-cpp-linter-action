/** This is a very ugly test code (doomed to fail linting) */
#include "demo.hpp"
#include <cstdio>
#include <cstddef>

// using size_t from cstddef
size_t dummyFunc(size_t i) { return i; }

int main()
{
    for (;;)
        break;

    printf("Hello world!\n");

    return 0;
}

// added to test cpp-linter-action#501 (temporary)
int  addNumbers( int a,int b ){
    int* unused = NULL;
  if(a>b) return a+b;
    return b+a ;
}
