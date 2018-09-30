#include <iostream>

int foo()
{
    std::cout << "Hello" << "\n";
    return 2;
}

int bar()
{
    int* m[1];
    m[2] = reinterpret_cast<int*>(&foo);
    return 1;
}

int main()
{
    bar();
}
