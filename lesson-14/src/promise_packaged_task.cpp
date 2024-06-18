#include <iostream>
#include <chrono>
#include <future>

std::future<int> runTask()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();
    auto task = [](std::promise<int>&& p)
    {
        std::cout << "before set_value" << std::endl;
        p.set_value(1);
        std::cout << "after set_value" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "finish" << std::endl;

    };
    std::thread thread(task, std::move(promise));
    thread.detach();
    return future;
}

int main()
{
    std::future<int> task = runTask();
    std::cout << "get task value: " << task.get() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
