#include <iostream>
#include <string>
#include <type_traits>
#include <cctype>
#include <utility>

struct Foo
{
    Foo(std::string s = "") : s(s) { std::cout << "constructor" << std::endl; }
    Foo(Foo& other) : s(other.s) { std::cout << "copy constructor" << std::endl; }
    Foo(Foo&& other) : s(std::exchange(other.s, "")) { std::cout << "move constructor" << std::endl; }

    std::string s;
};

void foo(int&& i) {}

int main()
{
    std::string s = "test";
    std::string& lvalue = s;
    // std::string&& rvalue = s; // lvalue can not be assigned to rvalue reference
    std::string&& rvalue = "test";

    int i = 5;
    int& r1 = i;
    // int&& r2 = i;
    int&& r3 = 5;
    int&& r4 = i + i;

    foo(5);
    // foo(i);

    Foo f0("test");
    Foo f1{f0};
    Foo f2{std::move(f1)};
    std::cout << "f0: " << f0.s << std::endl;
    std::cout << "f1: " << f1.s << std::endl;
    std::cout << "f2: " << f2.s << std::endl;
}
