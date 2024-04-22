#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

int main() {
    std::unordered_map<int32_t, std::string> counter;
    std::unordered_multimap<int32_t, std::string> counter_2;

    for (int i = 0; i < 10; ++i) {
        counter.insert(std::make_pair(i, std::to_string(i)));

        counter_2.insert({i, std::to_string(i)});
        counter_2.insert({i, std::to_string(-i)});
    }

    for (const auto &[key, value] : counter) {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }
    std::cout << std::endl;

    auto to_find = 3;
    if (counter.count(to_find)) {
        auto it = counter.find(to_find);
        std::cout << "key: " << it->first << " value: " << it->second << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    std::cout << std::endl;

    for (const auto& e : counter_2)
        std::cout << '{' << e.first << ',' << e.second << "} ";

    std::cout << counter_2.count(1) << std::endl;

    std::cout << counter.bucket_count() << std::endl;
    std::cout << counter_2.bucket_count() << std::endl;
}

