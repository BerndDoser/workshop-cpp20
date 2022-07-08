#include <ranges>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    std::vector<int> a{9,8,7};
    std::vector<std::string> b{"a", "b", "c"};

    std::stringstream ss;
    for (auto&& [a,b] : std::views::zip(a, b)) {
        ss << a << b;
    }
}