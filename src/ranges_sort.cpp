#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

namespace ra = std::ranges;
namespace rv = std::views;

int main()
{
    std::vector<int> v{ 21, 1, 3, 8, 13, 1, 5, 2 };
    //auto r = std::move(v) | ra::sort | ra::unique | rv::reverse;
    v |= ra::sort | ra::unique | rv::reverse;
    std::cout << rv::all(r) << '\n';
}
