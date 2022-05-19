#include <vector>
#include <ranges>

int main()
{
    std::vector<int> v{ 21, 1, 3, 8, 13, 1, 5, 2 };
    v = std::move(v) | 
    std::views::sort | 
    std::views::unique | 
    std::views::reverse;
}
