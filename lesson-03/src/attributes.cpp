#include <string>

enum class Status
{
    OK,
    ERROR
};

[[nodiscard("Possibly there is a memory leak")]]
int* magicFunction()
{
    return new int[1024];
}

[[nodiscard("Returned value must be handled")]]
Status getContent([[maybe_unused]] const std::string& url)
{
    Status status = Status::OK;
    // ...
    return status;
}

int main()
{
    [[maybe_unused]] Status status = getContent("https://vk.com");
    [[maybe_unused]] int* arr = magicFunction();
}
