#include <algorithm>
#include <iostream>
#include <string>
#include <ranges>

// 1 -
// 1 -+
// 2 +-
// 0 +++
// 3 --+-
// ++--+-

int main()
{
    std::string stack{"+--"};
    auto pos = std::ranges::find(std::views::reverse(stack), '-');
    std::cout << *pos << std::endl;
    std::cout << std::distance(std::rbegin(stack), pos) << std::endl;

    auto flip = [](const char c){
        return c == '+' ? '-' : '+';   // Conditional/Ternary operator
    };

    int n = 0;
    for (auto first = std::ranges::find(stack, '-'); first != std::end(stack); first = std::ranges::find(stack, '-'), n++)
    {
        if (stack[0] == '+') {
            auto sub = std::ranges::subrange(std::begin(stack), first + 1);
            std::ranges::transform(sub, std::begin(sub), flip);
        } else {
            auto last_unhappy = std::ranges::find(std::views::reverse(stack), '-');
            auto sub = std::ranges::subrange(std::begin(stack), first + 1);
            std::ranges::transform(sub, std::begin(sub), flip);
            std::ranges::reverse(sub);
        }

        std::ranges::for_each(stack, [](const char i){ std::cout << i; });
        std::cout << std::endl;
    }

    std::cout << "You need " << n << " flips to make all happy." << std::endl;

    return 0;
}
