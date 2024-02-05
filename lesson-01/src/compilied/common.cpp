#include "common.hpp"

int foo(int a, int b)
{
    return a + b;
}

void foo(char *str)
{
}

int Data::foo(int a, int b)
{
    return a + b;
}
