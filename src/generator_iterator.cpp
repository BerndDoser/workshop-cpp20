#include <iostream>

class range
{
private:
    int last;
    int iter;

public:
    range(int end) : last(end),
                     iter(0)
    {
    }

    // Iterable functions
    const range &begin() const { return *this; }
    const range &end() const { return *this; }

    // Iterator functions
    bool operator!=(const range &) const { return iter < last; }
    void operator++() { ++iter; }
    int operator*() const { return iter; }
};

int main()
{
    for (int i : range(10))
    {
        std::cout << i << std::endl;
    }
    return 0;
}