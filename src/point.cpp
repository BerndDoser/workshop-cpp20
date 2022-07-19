#include <set>
#include <cassert>

template<typename T1, typename T2>
void TestComparisons(T1 a, T2 b)
{
    (a < b), (a <= b), (a > b), (a >= b), (a == b), (a != b);
}

struct Point
{
    Point(int x, int y)
     : x(x), y(y)
    {}

    friend bool operator == (const Point& A, const Point& B) {
        return true;
    }

    bool operator != (Point const& other) const {
        return true;
    }

    int x;
    int y;
};

int main()
{
    Point P1(1,2);
    Point P2(1,2);
    Point P3(2,1);
    Point P4(1,1);

    TestComparisons(P1, P2);

    assert(P1 == P2);
    assert(P1 != P3);
    assert(P4 < P1);

    std::set<Point> points;
    points.insert(Point(1,2));
}
