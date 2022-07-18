#include <iostream>
#include <ranges>

int main()
{
    auto odd = [](int i){ return i % 2 == 1; };
    auto isPrime = [](int i) {
        for (int j=2; j*j <= i; ++j){
            if (i % j == 0) return false;
        }
        return true;
    };

    for (int i: std::views::iota(1) | std::views::filter(odd)
                                    | std::views::filter(isPrime)
                                    | std::views::take(10))
    {
        std::cout << i << std::endl;
    }
}
