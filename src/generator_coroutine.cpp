#include <iostream>
#include <vector>
#include <coroutine>

template<typename T>
struct Generator {
  struct promise_type;
  using handle_type = std::coroutine_handle<promise_type>;

  struct promise_type {
    T value_;
    std::exception_ptr exception_;

    Generator get_return_object() {
      return Generator(handle_type::from_promise(*this));
    }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() { exception_ = std::current_exception(); }
    template<std::convertible_to<T> From> // C++20 concept
    std::suspend_always yield_value(From &&from) {
      value_ = std::forward<From>(from);
      return {};
    }
    void return_void() {}
  };

  handle_type h_;

  Generator(handle_type h) : h_(h) {}
  ~Generator() { h_.destroy(); }
  explicit operator bool() {
    fill();
    return !h_.done();
  }
  T operator()() {
    fill();
    full_ = false;
    return std::move(h_.promise().value_);
  }

private:
  bool full_ = false;

  void fill() {
    if (!full_) {
      h_();
      if (h_.promise().exception_)
        std::rethrow_exception(h_.promise().exception_);
      full_ = true;
    }
  }
};

Generator<int> generatorForNumbers(int begin, int inc = 1)
{
    for (int i = begin;; i += inc)
    {
        co_yield i;
    }
}

int main()
{
    const auto numbers = generatorForNumbers(-10);
  
    for (int i= 1; i <= 20; ++i) std::cout << numbers << " ";
                                                         
    for (auto n: generatorForNumbers(0, 5)) std::cout << n << " ";
}
