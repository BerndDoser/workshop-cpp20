#include <algorithm>
#include <iostream>
#include <string>
#include <ranges>

// 1 -
// 1 -+
// 2 +-
// 0 +++
// 3 --+-
// 4 ++--+-

int main()
{
    std::string stack{"++--+-"};

    auto flip = [](const char c){
        return c == '+' ? '-' : '+';   // Conditional/Ternary operator
    };

    int n = 0;
    for (auto first = std::ranges::find(stack, '-'); first != std::end(stack); first = std::ranges::find(stack, '-'), n++)
    {
        if (stack[0] == '+') {
            auto sub = std::ranges::subrange(std::begin(stack), first);
            std::ranges::transform(sub, std::begin(sub), flip);
        } else {
            auto first_happy = std::ranges::find(stack, '+');
            auto sub = std::ranges::subrange(std::begin(stack), first_happy);
            std::ranges::transform(sub, std::begin(sub), flip);
        }

        std::ranges::for_each(stack, [](const char i){ std::cout << i; });
        std::cout << std::endl;
    }

    std::cout << "You need " << n << " flips to make all happy." << std::endl;

    return 0;
}
