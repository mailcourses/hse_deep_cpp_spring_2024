#include <stdlib.h>
#include <stdio.h>

int func1(int i)
{
    static int j = 0;
    j += i;
    return j;
}

void func2(char *ch, int len)
{
    printf("String: [%s] len: [%d]\n", ch, len);
}

int sum(int* arr, int len)
{
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
        res += arr[i];
    }
    return res;
}

int fibonacci(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
