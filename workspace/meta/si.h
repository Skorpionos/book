#include "list_int.h"
#include <vector>

template<int m   = 0,
         int kg  = 0,
         int s   = 0,
         int A   = 0,
         int K   = 0,
         int mol = 0,
         int cd  = 0>
using Dimension = IntList<m, kg, s, A, K, mol, cd>;

const std::vector<std::string> names = {"m", "kg", "s", "A", "K", "mol", "cd"};

template <class L>
void PrintListFormat(std::vector<std::string>::const_iterator it);

template<typename D>
class Quantity
{
public:
    Quantity() = default;

    explicit Quantity(double value)
        : m_value {value}
    {};

    const double value() const {return m_value;};

    void Print()
    {
        std::cout << value();
        PrintListFormat<D>(names.cbegin());
    }

private:
    double m_value = 0;
};

using NumberQ      = Quantity<Dimension<>>;                    // число без размерности
using LengthQ      = Quantity<Dimension<1>>;                   // метры
using MassQ        = Quantity<Dimension<0, 1>>;                // килограммы
using TimeQ        = Quantity<Dimension<0, 0, 1>>;             // секунды
using CurrentQ     = Quantity<Dimension<0, 0, 0, 1>>;          // амперы
using TemperatureQ = Quantity<Dimension<0, 0, 0, 0, 1>>;       // кельвины
using Amount       = Quantity<Dimension<0, 0, 0, 0, 0, 1>>;    // моли
using LuminousQ    = Quantity<Dimension<0, 0, 0, 0, 0, 0, 1>>; // канделы

using VelocityQ = Quantity<Dimension<1, 0, -1>>;   // скорость, метры в секунду
using AccelQ    = Quantity<Dimension<1, 0, -2>>;   // ускорение, метры в секунду в квадрате
using ForceQ    = Quantity<Dimension<1, 1, -2>>;   // сила, ньютоны

auto operator"" _m   (long double x) { return LengthQ      {double (x)}; }
auto operator"" _kg  (long double x) { return MassQ        {double (x)}; }
auto operator"" _s   (long double x) { return TimeQ        {double (x)}; }
auto operator"" _A   (long double x) { return CurrentQ     {double (x)}; }
auto operator"" _K   (long double x) { return TemperatureQ {double (x)}; }
auto operator"" _mol (long double x) { return Amount       {double (x)}; }
auto operator"" _cd  (long double x) { return LuminousQ    {double (x)}; }

template<typename D>
Quantity<D> operator+(const Quantity<D> lhs, const Quantity<D> rhs)
{
    return Quantity<D> {lhs.value() + rhs.value()};
}

template<typename D>
Quantity<D> operator-(const Quantity<D> lhs, const Quantity<D> rhs)
{
    return Quantity<D> {lhs.value() - rhs.value()};
}

template<typename D>
Quantity<D> operator*(const Quantity<D> lhs, double factor)
{
    return Quantity<D> {lhs.value() * factor};
}

template<typename D>
Quantity<D> operator*(double factor, const Quantity<D> rhs)
{
    return rhs * factor;
}

template<typename D>
Quantity<D> operator/(const Quantity<D> lhs, double divisor)
{
    return Quantity<D> {lhs.value() / divisor};
}

template<int lhs, int rhs>
struct Plus
{
    static int const value = lhs + rhs;
};

template<int lhs, int rhs>
struct Minus
{
    static int const value = lhs - rhs;
};

template<typename D1, typename D2>
auto operator*(const Quantity<D1>& lhs, const Quantity<D2>& rhs) -> decltype(Quantity<typename Zip<D1, D2, Plus>::type>(lhs.value()))
{
    return Quantity<typename Zip<D1, D2, Plus>::type>(lhs.value() * rhs.value());
}

template<typename D1, typename D2>
auto operator/(const Quantity<D1>& lhs, const Quantity<D2>& rhs) -> decltype(Quantity<typename Zip<D1, D2, Minus>::type>(lhs.value()))
{
    return Quantity<typename Zip<D1, D2, Minus>::type>(lhs.value() / rhs.value());
}

template<typename D>
auto operator/(double dividend, const Quantity<D> rhs) -> decltype(Quantity<Dimension<>>(dividend) / rhs)
{
    return Quantity<Dimension<>>(dividend) / rhs;
}

template <class L>
void PrintListFormat(std::vector<std::string>::const_iterator it)
{
    const auto absValue = std::abs(L::Head);
    if (absValue != 0)
    {
        std::cout << (L::Head > 0 ? "*" : "/");
        std::cout << *it;
    }
    if (absValue > 1)
        std::cout << "^" << absValue;

    PrintListFormat<typename L::Tail>(++it);
}

template <>
void PrintListFormat<IntList<>>(std::vector<std::string>::const_iterator it)
{
    std::cout << std::endl;
}

//int main()
//{
//
//    auto f = 5.0_kg / 6.0_s * 100.0_m / 5.0_s;
//
//    util::ShowType(f);
//    std::cout << f.value() << "\n";
//
//    return util::PrintComplete();
//}

//#include "meta/si.h"
//#include "internal/io.h"
//
//int main()
//{
//
//    auto g = 9.8_m / 1.0_s / 1.0_s;
//    auto t = 6.0_s;
//    auto h = g * t * t / 2;
//
//    g.Print();
//    t.Print();
//    h.Print();
//
//    return util::PrintComplete();
//}
