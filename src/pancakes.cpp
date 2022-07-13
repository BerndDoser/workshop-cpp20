#include <algorithm>
#include <iostream>
#include <string>
#include <ranges>
#include <vector>

int main()
{
    //std::string stack{"-+-"};
    //auto stack{1,0,1,0};
    std::vector<int> stack{1,0,1,0};
    auto first = std::ranges::find(stack, 0);

    std::cout << *first << std::endl;
    std::cout << std::distance(std::begin(stack), first) << std::endl;

    auto flip = [](const int i){
        if (i == 1) return 0;
        else return 1;
    };

    auto s2 = stack | std::views::transform([](const int i){ return 5; });
    //std::cout << std::endl;

    //std::ranges::subrange(std::begin(stack), first + 1) |= std::views::transform(flip);

    std::ranges::for_each(stack, [](const int i){ std::cout << i; });
    std::cout << std::endl;

    int n = 0;
    std::cout << n << std::endl;

    return 0;
}
