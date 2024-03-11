#include <iostream>

class Foo
{
public:
    Foo() = default;
    Foo(const std::string& name) : name_(name) {}
    Foo(int64_t ts) : ts_(ts) {}
    Foo(const std::string& name, int64_t ts) : ts_(ts), name_(name) {}
    //Foo(const std::string& name, int64_t ts = 0) : ts_(ts), name_(name) {} // Compile Error
private:
    std::string name_;
    int64_t ts_ = 0;
};

int main()
{
    Foo foo1;
    Foo foo2("Walter"); // ?
    Foo foo3(1710170657);
    Foo foo4("Walter", 1710170657);
}
