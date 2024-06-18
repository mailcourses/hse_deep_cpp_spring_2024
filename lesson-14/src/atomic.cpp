#include <iostream>
#include <thread>
#include <atomic>

const size_t MAX_THREADS_CNT = 100;
std::atomic<int> gCounter = 0;

struct FooType
{
    int a;
};

std::atomic<FooType> gString;
//int gCounter = 0;

void foo()
{
    gCounter += 1;
}

int main()
{
    std::cout << "atomic int is lock free: " << gCounter.is_lock_free() << std::endl;
    std::cout << "atomic string is lock free: " << gString.is_lock_free() << std::endl;
    std::vector<std::thread> threads;
    for (size_t i = 0; i < MAX_THREADS_CNT; ++i) {
        threads.emplace_back(foo);
    }
    for (size_t i = 0; i < MAX_THREADS_CNT; ++i) {
        threads[i].join();
    }
    std::cout << "gCounter=" << gCounter << std::endl;

}
