#include <ranges>
#include <iostream>
 
int main()
{
    auto const data = {0, 1, 2, 3, 4, 5};
 
    auto result { data
        | std::views::transform([](const auto& value) {
            std::cout << "mult " << value << std::endl;
            return value * 2;
        })
    };

    std::cout << "here 1" << std::endl;
    std::cout << result[0] << std::endl;

    std::cout << "here 2" << std::endl;
    std::cout << result[3] << std::endl;
}