//#define DEBUG

#ifdef DEBUG

#include <iostream>

#endif

#define max(x, y) ((x) > (y) ? (x) : (y))

#define sqr(x) x * x

#define MAX(x, y, result)       \
{                               \
    const auto& _x = x;         \
    const auto& _y = y;         \
    result = _x > _y ? _x : _y; \
}

void test()
{
    int a = 10;
    int b = 17;

    const auto result = max(++a, b);

#ifdef DEBUG

    std::cout << result << "\n";

#endif

   const auto result2 = sqr(3 + 0);
}