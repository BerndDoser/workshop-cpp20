#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> stack{1,2,3,4,3,2,1};
    auto first = std::ranges::find(stack, 3);

    std::cout << *first << std::endl;
    std::cout << std::distance(std::begin(stack), first) << std::endl;

    auto last = std::ranges::find(std::views::reverse(stack), 3);

    std::cout << *last << std::endl;
    std::cout << std::distance(std::rbegin(stack), last) << std::endl;

    return 0;
}
