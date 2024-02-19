#include <iostream>

int foo(int num)
{
    static int j = 10;
    std::cout << "foo:j = " << j << std::endl;
    j += num;
    return j;
}

int main()
{
    for (size_t i = 1; i <= 5; ++i )
    {
        foo(i);
    }
}
