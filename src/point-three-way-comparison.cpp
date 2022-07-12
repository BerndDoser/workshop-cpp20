#include <set>
#include <cassert>
#include <compare>

struct Point
{
    Point(int x, int y)
     : x(x), y(y)
    {}

    std::strong_ordering operator <=> (Point const& other) const = default;

    int x;
    int y;
};

int main()
{
    Point P1(1,2);
    Point P2(1,2);
    Point P3(2,1);
    Point P4(1,1);

    assert(P1 == P2);
    assert(P1 != P3);
    assert(P4 < P1);

    std::set<Point> points;
    points.insert(P1);
}
