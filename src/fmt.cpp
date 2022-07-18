#include <cassert>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iostream>
#include <iomanip>
#include <numbers>
#include <vector>

int main()
{
    fmt::print("Hello, world!\n");

    std::string s = fmt::format("{1}, {0}!", "world", "Hello", "something");
    assert(s == "Hello, world!");
    std::cout << s << std::endl;

    std::vector<int> v = {1, 2, 3};
    fmt::print("{}\n", v);

    auto pi = std::numbers::pi_v<double>;  // C++20 introduce mathematical constants
    std::cout << std::setprecision(2) << std::fixed << pi << std::endl;

    fmt::print("{:.5f}\n", pi);

    fmt::print("{:<30}\n", "left aligned");
    fmt::print("{:>30}\n", "right aligned");
    fmt::print("{:^30}\n", "centered");
    fmt::print("{:*^30}\n", "centered");
}
