#include <algorithm>
#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

namespace rv = ranges::views;
namespace ra = ranges::actions;

int main()
{
    std::vector<int> v{ 21, 1, 3, 8, 13, 1, 5, 2 };

    //std::ranges::sort(v);
    //std::ranges::unique(v);
    //std::ranges::reverse(v);

    //auto r = std::move(v) | ra::sort | ra::unique | ra::reverse;
    v |= ra::sort | ra::unique | ra::reverse;

    //for (auto const e : r) std::cout << e << " ";
    std::cout << rv::all(v) << '\n';
}
