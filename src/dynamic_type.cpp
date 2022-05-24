#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Base
{ 
    virtual ~Base() = default;
    static const std::string name() { return "Base"; }
    virtual int getIdx() = 0;
};

struct Derived1 : public Base
{
    static const std::string name() { return "Derived1"; }
    virtual int getIdx() { return 0; }
};

struct Derived2 : public Base
{
    static const std::string name() { return "Derived2"; }
    virtual int getIdx() { return 1; }
};

using DynType = std::shared_ptr<Base>;

template <class T>
struct MyFunctor
{
    using Result = std::string;

    Result operator() (T const& t) {
        return T::name();
    }
    Result operator() (DynType const& dynType) {
        return this->operator()(*std::static_pointer_cast<T>(dynType));
    }
};

template <>
struct MyFunctor<DynType>
{
    using Result = std::string;
    using Function = std::function< Result(DynType const&) >;

    Result operator() (DynType const& dynType) {
        return dynFunc[dynType->getIdx()](dynType);
    }

    static Function dynFunc[2];
};

MyFunctor<DynType>::Function MyFunctor<DynType>::dynFunc[] =
{
    MyFunctor<Derived1>(),
    MyFunctor<Derived2>()
};

int main()
{
    Derived1 d1;
    std::cout << MyFunctor<Derived1>()(d1) << std::endl;

    Derived2 d2;
    std::cout << MyFunctor<Derived2>()(d2) << std::endl;

    DynType dyn1(new Derived1);
    std::cout << MyFunctor<DynType>()(dyn1) << std::endl;

    DynType dyn2(new Derived2);
    std::cout << MyFunctor<DynType>()(dyn2) << std::endl;
}
