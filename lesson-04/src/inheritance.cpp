#include <iostream>

class FooBase
{
public:
    FooBase()
    {
        std::cout << "FooBase::FooBase()" << std::endl;
    }

    void foo()
    {
        std::cout << "FooBase::foo" << std::endl;
    }

    ~FooBase()
    {
        std::cout << "FooBase::~FooBase()" << std::endl;
    }
public:
    int data = 100500;
};

class FooDerived : public FooBase
{
public:
    FooDerived()
    {
        std::cout << "FooDerived::FooDerived()" << std::endl;
    }

    void foo()
    {
        std::cout << "FooDerived::foo" << std::endl;
    }

    void magic()
    {
        std::cout << "FooDerived::magic" << std::endl;
    }

    ~FooDerived()
    {
        std::cout << "FooDerived::~FooDerived()" << std::endl;
    }
};

int main()
{
    {
        FooBase base;
        base.foo();
        std::cout << "FooBase::data = " << base.data << std::endl;
    }

    {
        FooDerived derived;
        derived.foo();
        std::cout << "FooDerived::data = " << derived.data << std::endl;
    }

    /// Pointers
    std::cout << "\n\nPointers\n\n";
    {
        FooBase* base = new FooBase();
        base->foo();
        std::cout << "FooBase::data = " << base->data << std::endl;
    }

    {
        FooBase* derived = new FooDerived();
        derived->foo();
        derived->magic();
        std::cout << "FooDerived::data = " << derived->data << std::endl;
    }
}
