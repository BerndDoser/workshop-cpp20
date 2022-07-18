#include <iostream>

void foo(int& a)
{
    std::cout << "foo & " << a << std::endl;
}

void foo(int&& a)
{
    std::cout << "foo && " << a << std::endl;
}

int main()
{
    int b = 1;
    foo(b);
    foo(2);
    foo(b + 3);

    //int&& c = b; //Error. An rValue reference cannot be pointed to a lValue.
    int&& d = 5;
}