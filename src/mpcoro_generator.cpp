#include <iostream>
#include <mp-coro/generator.h>

mp_coro::generator<std::uint64_t> fibonacci()
{
  std::uint64_t a = 0, b = 1;
  while (true) {
    co_yield b;
    a = std::exchange(b, a + b);
  }
}

int main()
{
  auto gen = fibonacci();
  for(auto i : std::views::counted(gen.begin(), 10))
    std::cout << i << ' ';
  std::cout << '\n';
}
