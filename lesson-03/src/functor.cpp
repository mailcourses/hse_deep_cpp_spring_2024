#include <iostream>
#include <functional>

using MoveFunction =
     std::function<void (int& x, int& y)>;

void moveLeft(int &x, int &y)
{
    std::cout << "moveLeft()" << std::endl;
}

struct Foo
{
    void operator()(int& x, int& y)
    {
        std::cout << "Foo::operator()" << std::endl;
    }
};

MoveFunction getRandomDirection() {
    return Foo();
}

int main()
{
    std::vector<MoveFunction> trajectory =
    {
        [](int& x, int& y)  {
            std::cout << "lambda" << std::endl;
        },
        moveLeft,
        getRandomDirection()
    };
    int a = 10;
    int b = 100;
    for (auto t : trajectory)
    {
        t(a, b);
    }
}
