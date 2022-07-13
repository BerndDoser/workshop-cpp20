#include <iostream>
#include <memory>

struct A
{
    A() {
        std::cout << "constructor" << std::endl;
    }

    ~A() {
        std::cout << "destructor" << std::endl;
    }
};

int main()
{
    //std::shared_ptr<A> ptr(new A[3]);   \\ memory leak
    std::shared_ptr<A> ptr(new A[3], std::default_delete<A[]>());
}
