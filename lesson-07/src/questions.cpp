#include <iostream>

struct A
{
    A() {
        std::cout << "default ctr" << std::endl;
    }

    A(int a) : data_(a)
    {
        std::cout << "int ctr (" << data_ << ")" << std::endl;
    }
    A(const A& lhs)
    {
        std::cout << "copy ctr" << std::endl;
    }
    /*A(A&& lhs) {
        std::cout << "move ctr" << std::endl;
    }*/
    ~A() {}

    A operator+(const A& lhs)
    {
        std::cout << "operator+" << std::endl;
        A tmp;
        tmp.data_ = data_ + lhs.data_;
        return tmp;
    }

    int data_;
};

A foo()
{
    A tmp(100);
    return tmp;
}

int main()
{
    int c = 10;
    A a = A(c) + A(20) + A(30);
    A b = foo();
}
