#include <variant>
#include <iostream>
#include <string>

class empty{};

int main()
{
    std::variant<int, double, std::string, float> v = 1;
    std::cout << v.index() << std::endl;
    v = 1.3f;
    std::cout << v.index() << std::endl;
    v = "hey";
    std::cout << v.index() << std::endl;

    std::cout << "type size:" << std::endl;
    std::cout << "0: " << sizeof(empty) << std::endl;
    std::cout << "1: " << sizeof(bool) << std::endl;
    std::cout << "2: " << sizeof(char) << std::endl;
    std::cout << "3: " << sizeof(int) << std::endl;
    std::cout << "4: " << sizeof(float) << std::endl;
    std::cout << "5: " << sizeof(double) << std::endl;

    std::cout << "variant size:" << std::endl;
    std::cout << "0: " << sizeof(std::variant<empty>) << std::endl;
    std::cout << "1: " << sizeof(std::variant<bool>) << std::endl;
    std::cout << "2: " << sizeof(std::variant<char>) << std::endl;
    std::cout << "3: " << sizeof(std::variant<char, bool>) << std::endl;
    std::cout << "4: " << sizeof(std::variant<int>) << std::endl;
    std::cout << "5: " << sizeof(std::variant<int, empty>) << std::endl;
    std::cout << "6: " << sizeof(std::variant<int, double, bool>) << std::endl;
    std::cout << "7: " << sizeof(std::variant<int, double, bool, char>) << std::endl;
}
