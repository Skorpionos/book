#include <iostream>
#include "internal/io.h"

struct Foo
{
    void say() const
    {
        std::cout << "Foo says: " << msg << "\n";
    }

protected:
    Foo(const char* msg)
        : msg(msg)
    {}

private:
    const char* msg;
};

void foo_says(const Foo& foo)
{
    foo.say();
}

Foo get_foo(const char *msg)
{
    struct Bar : Foo
    {
        Bar(const char* msg)
            : Foo(msg) {}
    };

    return Bar(msg);
}

//struct get_foo : Foo
//{
//    explicit get_foo(const char* msg) : Foo(msg) {}
//};

int main()
{
    util::ShowType(get_foo("Hi!"));
    foo_says(get_foo("Hi!"));
}