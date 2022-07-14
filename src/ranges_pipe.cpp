#include <iostream>
#include <utility>

template<class F>
struct pipe_closure : F
{
    template<class... Xs>
    pipe_closure(Xs&&... xs) : F(std::forward<Xs>(xs)...)
    {}
};

template<class T, class F>
decltype(auto) operator|(T&& x, const pipe_closure<F>& p)
{
    return p(std::forward<T>(x));
}

struct add_one_f
{
    template<class T>
    auto operator()(T x) const
    {
        return x + 1;
    }
};

int main()
{
    const pipe_closure<add_one_f> add_one = {};
    int result = 1 | add_one | add_one;
    std::cout << result << std::endl;
}
