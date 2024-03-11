#include <iostream>
#include <type_traits>

struct Bat
{
};

struct Cat : Bat
{
    char n;
    int age;
};

template<class T>
struct is_pod
{
    static const bool value = false;
};

/*template<Cat>
struct is_pod
{
    static const bool value = true;
};*/

struct A { int m; };
static_assert(std::is_standard_layout_v<A> == true);
 
class B: public A { int m; };
static_assert(std::is_standard_layout_v<B> == false);
 
struct C { virtual void foo(); };
static_assert(std::is_standard_layout_v<C> == false);

class RankerBase
{
public:
    virtual void search(const std::string& query)
    {
        std::cout << "RankerBase::search" << std::endl;
    }

    virtual ~RankerBase()
    {
        std::cout << "RankerBase::~RankerBase" << std::endl;
    }
};

class RankerYoula : public RankerBase
{
public:
    void search(const std::string& query) override
    {
        std::cout << "RankerYoula::search" << std::endl;
    }
    ~RankerYoula()
    {
        std::cout << "RankerYoula::~RankerYoula" << std::endl;
    }
};

class RankerDzen : public RankerBase
{
public:
    RankerDzen()
    {
        data_ = new int[1024];
    }
    void search(const std::string& query) override
    {
        std::cout << "RankerDzen::search" << std::endl;
    }

    void super_fast_search()
    {
    }
    ~RankerDzen()
    {
        std::cout << "RankerDzen::~RankerDzen" << std::endl;
        delete[] data_;
    }

    int* data_ = nullptr;

};

void retriever(RankerBase* ranker)
{
    ranker->search("cats");
}

RankerBase* fabric(const std::string& config)
{
    if( config == "youla")
        return new RankerYoula();
    if( config == "dzen")
        return new RankerDzen();
    return new RankerBase();
}

int main()
{
    std::cout << "sizeof(Cat) = " << sizeof(Cat) << std::endl;
    std::cout << "sizeof(std::string) = " << sizeof(std::string) << std::endl;
    //std::cout << "is_pod(Cat) = " << std::is_pod<Cat>::value << std::endl;
    std::cout << "is_standard_layout(Cat) = " << std::is_standard_layout_v<Cat> << std::endl;
    std::cout << "is_trivial_layout(Cat) = " << std::is_trivial_v<Cat> << std::endl;

    //===============
    std::cout << "sizeof(RankerBase) = " << sizeof(RankerBase) << std::endl;
    std::cout << "sizeof(RankerDzen) = " << sizeof(RankerDzen) << std::endl;
    std::cout << "sizeof(RankerYoula) = " << sizeof(RankerYoula) << std::endl;
    RankerBase* youla_ranker = fabric("youla");
    RankerBase* dzen_ranker = fabric("dzen");
    retriever(youla_ranker);
    retriever(dzen_ranker);

    delete youla_ranker;
    delete dzen_ranker;
}
