#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v{5, 7, -4, 2};
	std::ranges::sort(v);
    fmt::print("{}\n", v);

    for (auto && e : v)
        std::cout << e << " ";
}
