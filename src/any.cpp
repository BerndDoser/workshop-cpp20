#include <any>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::any> v{ 5, 4.5, "hey" };
    std::cout << std::any_cast<int>(v[0]) << std::endl;
    std::cout << std::any_cast<double>(v[1]) << std::endl;
    std::cout << std::any_cast<const char*>(v[2]) << std::endl;
}
