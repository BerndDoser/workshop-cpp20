#include <type_traits>
#include <utility>
#include <iostream>

struct Foo
{
    Foo(int i = 0) : i(i) {}
    Foo(Foo& other) : i(other.i) { std::cout << "copy" << std::endl; }
    Foo(Foo&& other) : i(std::exchange(other.i,0)) { std::cout << "move" << std::endl; }

    int i;
};

int main()
{
    auto a = 2;
    auto b = a;
    static_assert(std::is_same<decltype(a), int>::value);

    Foo f0(2);
    Foo f1{f0};
    Foo f2{std::move(f0)};
    std::cout << f2.i << std::endl;
    std::cout << f0.i << std::endl;
}
