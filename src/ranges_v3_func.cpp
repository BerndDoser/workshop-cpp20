#include <vector>
#include <iostream>
#include <range/v3/all.hpp>

std::vector<int> get_vector() { return {1, 2, 3}; }

void func1()
{
   auto&& vec = get_vector();
    
    auto const v1 = 
    vec |
    ranges::views::transform([](auto const& i) { return i + 1; }) |
    ranges::to_vector;

    for (auto i : v1)
        std::cout << i;
}

int main()
{
    func1();
}