// gcc -std=c++11 -pthread

#include <chrono>
#include <future>
#include <iostream>

int main()
{
    std::future<void> f1(std::async(std::launch::async, []()
        {
            for (int i(0); i != 10; ++i) {
                std::cout << "A" << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }));

    std::future<void> f2(std::async(std::launch::async, []()
        {
            for (int i(0); i != 10; ++i) {
                std::cout << "B" << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }));

    f1.get();
    f2.get();
}
