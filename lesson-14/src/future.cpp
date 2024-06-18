#include <iostream>
#include <future>

int main()
{
    auto f =
        std::async(std::launch::async, []() { std::this_thread::sleep_for(std::chrono::seconds(3)); return 5; });
    //    std::async(std::launch::deferred, []() { std::this_thread::sleep_for(std::chrono::seconds(3)); return 5; });
    auto status = f.wait_for(std::chrono::seconds(1));
    while (true) {
        if (status == std::future_status::deferred) {
            std::cout << "задача еще не стартовала" << std::endl;
            f.wait();
        }
        else if (status == std::future_status::timeout) {
            std::cout << "результата не дождались" << std::endl;
        }
        else if (status == std::future_status::ready) {
            std::cout << "все готово; " << f.get() << std::endl;
            break;
        }
        status = f.wait_for(std::chrono::seconds(1));
    }
}
