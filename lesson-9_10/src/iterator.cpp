#include <iostream> 
#include <initializer_list>
#include <iterator> 

using namespace std;

template<class T>
class ArrayIterator : public std::iterator<std::forward_iterator_tag, T> {
public:
    using reference = T&;
    using pointer = T*;
    using value_type = T;

    ArrayIterator(T* ptr): m_Ptr(ptr) {}

    T& operator*() {
        return *m_Ptr;
    }
    
    ArrayIterator& operator++() {
        ++m_Ptr;
        return *this;
    }

    bool operator==(ArrayIterator& other) {
        return other.m_Ptr == m_Ptr;
    }

    bool operator!=(ArrayIterator& other) {
        return other.m_Ptr != m_Ptr;
    }



private:
    T* m_Ptr;
};

template<class T, size_t size>
class Array {
public:
    using iterator = ArrayIterator<T>;

    Array(std::initializer_list<T> init) {

        auto end = init.end();
        auto it = init.begin();

        for (size_t i = 0; it != end; ++it, ++i) {
            m_Data[i] = *it;
        }
    }

    iterator begin() noexcept
    {
        return iterator(m_Data);
    }

    iterator end() noexcept
    {
        return iterator(m_Data + size);
    }

private:
    std::array“
};

int main() {
    Array<std::string, 10> a {"cat", "cacao", "dog"};
    auto end = a.end();
    for (auto it = a.begin(); it != end; ++it) {
        std::cout << "Value = '" << *it << "'" << std::endl;
    }
}