#include <stdint-gcc.h>

namespace study::math
{

template <class T>
T Log(T a)
{
    T x = 1;
    T i = 0;

    while (x * 2 <= a)
    {
        ++i;
        x *= 2;
    }

    return i;
}

//{
//    auto n = util::Input<uint64_t>();
//
//    while (n--)
//        std::cout << study::math::Log(util::Input<uint64_t>()) << "\n";
//}

//GCD(a,b)=GCD(b,amodb)
//GCD(0,a)=a
//GCD(a,b)=GCD(b,a)

uint64_t gcd(uint64_t a, uint64_t b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}


} // namespace study::math