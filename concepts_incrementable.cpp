template <typename T>
concept Incrementable = requires(T x) { x++; ++x; };

struct Foo
{
    void operator++() {};
};

void bar(Incrementable auto t) {}

int main()
{
    Foo foo;
    bar(foo);
}
