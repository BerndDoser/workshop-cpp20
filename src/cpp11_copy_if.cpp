#include <algorithm>
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> data{42, 1, 12, -3, 14, -5};
 
    for (auto const& e : data) std::cout << e << " ";
    std::cout << std::endl;

    std::vector<int> pos;

    // copy only positive numbers:
    std::copy_if (data.begin(), data.end(), std::back_inserter(pos), [](int i){return i>=0;} );

    for (auto const& e : pos) std::cout << e << " ";
    std::cout << std::endl;
}
