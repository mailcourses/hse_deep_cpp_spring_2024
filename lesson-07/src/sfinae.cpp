#include <iostream>
#include <limits>
#include <climits>

struct A
{
};

struct B
{
    void optimize() const {}
};

struct C
{
    std::string optimize() const { return std::string(); }
};

struct D : public B
{
};

template<class T, class U>
struct my_is_same
{
    static constexpr bool value = false;
};

template<class T>
struct my_is_same<T, T>
{
    static constexpr bool value = true;
};

template<class T>
struct has_optimize
{
public:
    static constexpr bool value = my_is_same<void, decltype(has_optimize<T>::check( (T*)nullptr) )>::value;
private:
    static int32_t check(...);

    template<class U>
    static auto check(U* u) -> decltype(u->optimize());
};

template<class T>
void run(const T& obj,
         typename std::enable_if<!has_optimize<T>::value>::type* = nullptr)
{
    std::cout << "Not optimized version" << std::endl;
}

template<class T>
void run(const T& t,
         typename std::enable_if<has_optimize<T>::value>::type* = nullptr)

    std::cout << "Optimized version" << std::endl;
    t.optimize();
}

int main()
{
    std::cout << LONG_MAX << std::endl;
    std::cout << std::numeric_limits<int64_t>::max() << std::endl;
    std::cout << std::numeric_limits<uint64_t>::max() << std::endl;

    std::cout << std::boolalpha << has_optimize<A>::value << std::endl;
    std::cout << has_optimize<B>::value << std::endl;
    std::cout << has_optimize<C>::value << std::endl;
    std::cout << has_optimize<D>::value << std::endl;

    run(A());
    run(B());
    run(C());
}

