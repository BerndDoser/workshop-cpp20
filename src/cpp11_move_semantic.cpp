#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

struct Foo
{
    Foo(std::string s) : s(s) {}
    Foo(Foo& other) : s(other.s) { std::cout << "copy" << std::endl; }
    Foo(Foo&& other) : s(std::exchange(other.s, "empty")) { std::cout << "move" << std::endl; }

    std::string s;
};

int main()
{
    Foo f0("test");
    Foo f1{f0};
    Foo f2{std::move(f0)};
    std::cout << f2.s << std::endl;
    std::cout << f0.s << std::endl;
}
