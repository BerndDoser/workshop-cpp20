#include <type_traits>

struct Foo
{
    int i;
};

int main()
{
    auto a = 2;
    auto b = a;
    static_assert(std::is_same<decltype(a), int>::value);

    Foo f1{2};  // Copy constructor
    Foo f2{a};  // Move constructor
}
