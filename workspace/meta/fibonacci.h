template <int N>
struct Fib
{
    const static int value = Fib<N-1>::value + Fib<N-2>::value;
};

template <>
struct Fib<0>
{
    const static int value = 0;
};

template <>
struct Fib<1>
{
    const static int value = 1;
};

int main()
{
    std::cout << Fib<0>::value << "\n";
    std::cout << Fib<1>::value << "\n";
    std::cout << Fib<2>::value << "\n";
    std::cout << Fib<3>::value << "\n";
    std::cout << Fib<4>::value << "\n";
    std::cout << Fib<5>::value << "\n";
    std::cout << Fib<6>::value << "\n";

    util::PrintComplete();
}
