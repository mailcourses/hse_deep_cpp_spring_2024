#include <iostream>
#include <chrono>
#include <source_location>

using duration_t = std::chrono::microseconds;

class Profiler
{
public:
    Profiler(const std::source_location &location =
                   std::source_location::current())
    {
        // взять отсечку по времени -- start_ts
        start_ts_ = std::chrono::system_clock::now();
        location_ = location;
    }

    ~Profiler()
    {
        // взять отсечку по времени -- end_ts
        auto end_ts = std::chrono::system_clock::now();
        auto ts = std::chrono::duration_cast<duration_t>( end_ts - start_ts_ ).count();
        std::cout << "Time of execution of function " << location_.function_name() << " is " << ts << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> start_ts_;
    std::source_location location_;
};

void foo()
{
    Profiler prf;
    // ...
    for (size_t i = 0; i < 1000000; ++i);
}

void boo()
{
    Profiler prf;
    // ...
    for (size_t i = 0; i < 1000000 / 2; ++i);
}

int main()
{
    foo();
    boo();
}
