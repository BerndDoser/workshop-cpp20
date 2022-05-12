#include <cassert>

class Point
{
public:
    Point (int x, int y)
     : x(x), y(y)
    {}

    auto operator <=> (Point const& p) const = default;

private:
    int x, y;
};

int main()
{
    Point p1(1, 2);
    Point p2(1, 1);
    assert(!(p1 == p2));
    assert(p1 != p2);
}
