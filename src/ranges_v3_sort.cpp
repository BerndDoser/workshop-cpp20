#include <algorithm>
#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

namespace rv = ranges::views;
namespace ra = ranges::actions;

int main()
{
    std::vector<int> v{ 21, 1, 3, 8, 13, 1, 5, 2 };

    //std::ranges::reverse(v);
    //std::ranges::sort(v);
    //std::ranges::unique(v);

    //v |= ra::sort | rv::reverse | rv::unique;
    //auto r = v | ra::sort | rv::reverse | rv::unique;
    auto r = std::move(v) | ra::sort;

    //for (auto const e : r) std::cout << e << " ";
    std::cout << rv::all(r) << '\n';
}
