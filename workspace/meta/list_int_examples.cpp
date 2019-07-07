//template <typename F, typename ... Ts>
//auto apply(F&& f, std::tuple<Ts...> t)
//{
//    const auto size = sizeof...(Ts);
//
//    using List = typename Generate<size>::type;
//
//    return apply_impl(f, t, List {});
//};

//int main()
//{
//    using primes = IntList<2,3,5,7,11,13>;
//
//    std::cout << primes::Head << "\n";
//    std::cout << primes::Tail::Head << "\n";
//    std::cout << primes::Tail::Tail::Head << "\n";
//    std::cout << primes::Tail::Tail::Tail::Head << "\n";
//    std::cout << primes::Tail::Tail::Tail::Tail::Head << "\n";
//    std::cout << primes::Tail::Tail::Tail::Tail::Tail::Head << "\n";
//    std::cout << primes::Tail::Tail::Tail::Tail::Tail::Head << "\n";
//
//    util::PrintBreak('-');
//    std::cout << Length<primes>::value << "\n";
//    std::cout << Length<primes::Tail>::value << "\n";
//    std::cout << Length<primes::Tail::Tail>::value << "\n";
//    std::cout << Length<primes::Tail::Tail::Tail>::value << "\n";
//    std::cout << Length<primes::Tail::Tail::Tail::Tail>::value << "\n";
//    std::cout << Length<primes::Tail::Tail::Tail::Tail::Tail>::value << "\n";
//    std::cout << Length<primes::Tail::Tail::Tail::Tail::Tail::Tail>::value << "\n";
//
//
//    util::PrintComplete();
//}

//int main()
//{
//    using L1 = IntList<1, 2>;
//    using L2 = IntList<3, 4, 5>;
//
//    using L3 = Concat<L1, L2>::type;
//    std::cout << "length: " << Length<L3>::value << "\n";
//    std::cout << L3::Head << "\n";
//
//    using G = Generate<5>::type;
//    std::cout << "length: " << Length<G>::value << "\n";
//    std::cout << G::Head << "\n";
//    std::cout << G::Tail::Head << "\n";
//    std::cout << G::Tail::Tail::Head << "\n";
//    std::cout << G::Tail::Tail::Tail::Head << "\n";
//    std::cout << G::Tail::Tail::Tail::Tail::Head << "\n";
//
////    CheckType<G>();
////    Print<G>();
//    util::ShowType<G>();
//}


//int main()
//{
//    auto f = [](int x, int y, int z, int w) { return x * y * z * w; };
//    auto t = std::make_tuple(1, 2, 3, 4);
//    auto result = ::apply(f, t);
//    std::cout << result << "\n";
//    return util::PrintComplete();
//}

// бинарная метафункция
//template<int a, int b>
//struct Plus
//{
//    static int const value = a + b;
//};
//
//// два списка одной длины
//using L1 = IntList<1, 2, 3, 4, 5>;
//using L2 = IntList<1, 3, 7, 7, 2>;
//
//int main()
//{
//    using L3 = zip_t<L1, L2, Plus>;  // IntList<2, 5, 10, 11, 7>
//
//    util::ShowType<L3>();
//
//    return util::PrintComplete();
//}
