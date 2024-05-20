#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};

int area(struct Point *p1, struct Point *p2)
{
    return abs((p1->x - p2->x) * (p1->y - p2->y));
}

int fibonacci(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
