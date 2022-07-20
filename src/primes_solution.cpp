#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <ranges>

int main()
{
    auto isPrime = [](int i) {
        for (int j=2; j*j <= i; ++j){
            if (i % j == 0) return false;
        }
        return true;
    };

    auto primes = std::views::iota(1) | std::views::filter(isPrime)
                                      | std::views::take(10);

    fmt::print("{}\n", primes);

    return 0;
}
