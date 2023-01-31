# https://godbolt.org/z/hYY1rrjnh

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <range/v3/all.hpp>
#include <vector>

namespace rv = ranges::views;
namespace ra = ranges::actions;

int main()
{
    auto v1 = std::vector{1,2,3};
    auto v2 = std::vector{4,5};
    auto r1 = rv::concat(v1, v2);

    fmt::print("r1: {}\n", r1);

    v1.insert(std::end(v1), std::begin(v2), std::end(v2));

    fmt::print("r1: {}\n", r1);

    ra::insert(v1, std::end(v1), v2);
    fmt::print("v1: {}\n", v1);

    std::vector v3(std::begin(r1), std::end(r1));

    fmt::print("v3: {}\n", v3);    
}
