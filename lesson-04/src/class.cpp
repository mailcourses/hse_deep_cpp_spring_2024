#include <iostream>

enum class DachshundType
{
    Standart,
    Small,
    Tiny
};

struct Boo
{
    Boo() = delete;
    Boo(int32_t data) : data_(data)
    {
        std::cout << "ctr Boo()" << std::endl;
    }
    int32_t data_ = 500;
};

struct Foo
{
    Foo() = delete;
    Foo(const Boo& boo)
    {
        std::cout << "ctr Foo() " << boo.data_ << std::endl;
    }
};

struct Dachshund
{
//public:
    //Dachshund() {}
    Dachshund(/*Dachshund* this,*/
                uint32_t age,
                uint32_t weight,
                const DachshundType& type) : age_(age), weight_(weight), type_(type), boo_(10), foo_(boo_)
    {
        /*age_ = age;
        this->weight_ = weight;*/
    } // конструктор
    ~Dachshund() {}                        // деструктор
    Dachshund(const Dachshund& rhs) = default;  // конструктор копирования
    void nonconst_method()
    {
    }

    void print(/*const Dachshund& this*/) const
    {
        std::cout << "age = " << age_ << ", weight = " << weight_ << std::endl;
        /*this->*/age_ -= 1;
        //nonconst_method(); CE
    }

    static void debug()
    {
        std::cout << "debug " << name << std::endl;
    }
private:
    mutable uint32_t age_ = 100500;                      // закрытый член класса
    uint32_t weight_ = 500100;
    static constexpr char* name = "ROKSY";
    const DachshundType& type_;
    Boo boo_;
    Foo foo_;
};

int main()
{
    DachshundType type = DachshundType::Standart;
    Dachshund roksy(14, 5, type);
    roksy.print();
    //std::cout << "age of roksy is [" << roksy.age_ << "]" << std::endl;
    const Dachshund shokolad(roksy);
    shokolad.print();
    shokolad.debug();
    Dachshund::debug();
}
