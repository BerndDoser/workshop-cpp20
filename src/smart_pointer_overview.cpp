#include <memory>
#include <cassert>

int main()
{
    int* p0 = new int(0);
    auto p00 = std::shared_ptr<int>(p0);

    auto p1 = std::make_shared<int>(1);
    auto p2 = p1;
    assert(*p2 == 1);
    assert(p1.use_count() == 2);

    auto p3 = std::make_unique<int>(2);
    // auto p4 = p3;   // unique_ptr can't be copied
    auto p5 = std::move(p3);
    assert(*p5 == 2);
    assert(p3 == nullptr);

    // auto p6 = std::weak_ptr<int>(3);  // weak_ptr can't own
    auto p6 = std::weak_ptr<int>(p1);
    assert(p6.use_count() == 2);
    p1.reset();
    p2.reset();
    assert(p6.expired());
}
