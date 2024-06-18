#include <iostream>
#include <thread>
#include <map>
#include <chrono>

static thread_local std::map<std::string, int> threadCache;
static int32_t staticCounter = 2;
extern int32_t globalCounter = 10;

void writable_foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    threadCache["world"] = 100500;
    std::cout << "[writable_foo]" << std::endl;
}

void readable_foo()
{
    size_t seconds = 30;
    for (size_t i = 0; i < seconds; ++i)
    {
        std::cout << "[readable_foo] iteration #" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    threadCache["hello"] = 10;
    for(auto it = std::begin(threadCache); it != std::end(threadCache); ++it)
    {
        std::cout  << "[readable_foo] key=" << it->first << ", value=" << it->second << std::endl;
    }
}


int main()
{
    std::cout << "hardware_concurrency: " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "staticCounter: " << staticCounter << std::endl;

    threadCache["hello"] = 10;

    {
        std::thread t1(writable_foo);
        std::thread t2(readable_foo);

        t1.join();
        t2.detach();
    }
    std::cout << "after unknown namespace" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
