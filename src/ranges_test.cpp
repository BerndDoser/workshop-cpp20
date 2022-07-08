#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

struct Molecule
{
    std::vector<int> atoms;
};

int main()
{
    auto const ints = {0,1,2,3,4,5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    auto size = [](std::string const& s) { return std::size(s); };
    auto to_upper = [](std::string const& s) {
        return s | std::views::transform([](char c){ return std::toupper(c); });
    };
    auto too_long = [](std::string const& s) { return std::size(s) > 10; };

    //for std::views::iota(0) | std::views::filter(even) | std::views::transform(square);

    // auto text = "Lorem ipsum dolor sit amet";
    // auto count = std::string_view(text)
    //              | std::views::split(' ')
    //              | std::views::transform(size);

    auto text = {"Test", "das", "sddfwefwfewfe"};
    auto count = text | std::views::transform(to_upper);
//                      | std::views::transform(size);

    // for(auto n : std::views::all(count)) {
    //     std::cout << n << ' ';
    // }

    std::string s{"Test"};
    std::string s2 = s | std::views::transform([](char c){ return std::toupper(c); });

    std::cout << s2;
}