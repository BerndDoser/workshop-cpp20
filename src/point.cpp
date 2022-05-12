#include <cassert>

class Point
{
public:
    Point (int x, int y)
     : x(x), y(y)
    {}
    friend bool operator == (Point const& p1, Point const& p2) { return p1.x == p2.x && p1.y == p2.y; }
private:
    int x, y;
};

int main()
{
    Point p1(1, 2);
    Point p2(1, 1);
    assert(p1 == p2);
}
