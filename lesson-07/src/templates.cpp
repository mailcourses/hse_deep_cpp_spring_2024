#include <iostream>
#include <vector>

template <int N>
int foo()
{
    return N * 2;
}

template <double N>
double foo()
{
    return N * 2;
}

template<class X, class Y>
class Foo
{
public:
    Foo() = default;
private:
    X data_;
    Y counter_;
};

template<class T>
using IntFoo = Foo<int, T>;

typedef Foo<int, size_t> IntFoo2;

template<class Containter, class Index>
auto getAccess(Containter c, Index i) -> decltype(c[i])
{
    return c[i];
}

constexpr int sum(int a, int b)
{
    return a + b;
}

void moo()
{
    {
        int x1 = 10, y1 = 20;
        std::cin >> x1 >> y1;
        int c = sum(x1, y1);
        //constexpr int d = sum(x1, y1);
    }
}

int main()
{
    {
        std::cout << foo<10>() << std::endl;
        std::cout << foo<10.6>() << std::endl;

        const int x = 3;
        int& y = const_cast<int&>(x);
        y = 10;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << foo<x>() << std::endl;

        Foo<int32_t, size_t> foo;
        IntFoo<size_t> foo2;
    }

    {
        std::vector<int> c(10, -1);
        std::cout << getAccess(c, 0) << std::endl;
    }

    {
        int c = sum(5, 12);
        const int x1 = 10, y1 = 20;
        //std::cin >> x1 >> y1;
        constexpr int d = sum(x1, y1);
    }

    moo();
}
