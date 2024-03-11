#include <iostream>

class SmartPointer
{
public:
    using T = int32_t;
public:
    SmartPointer(T* rhs)
    {
        std::cout << "ctr SmartPointer" << std::endl;
        data_ = rhs;
    }

    ~SmartPointer()
    {
        std::cout << "dctr ~SmartPointer" << std::endl;
        delete data_;
    }
private:
    T* data_ = nullptr;
};

int main()
{
    SmartPointer ptr(new SmartPointer::T(100500));
    SmartPointer::T* i = new SmartPointer::T(100500);
    SmartPointer ptr_2(i);
}
