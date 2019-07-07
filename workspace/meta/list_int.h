#pragma once

#include <tuple>
#include <type_traits>
#include <iostream>
#include <array>
#include <vector>

//template <int ... integers>
template <int...>
struct IntList
{
};

template <int head, int ... T>
struct IntList<head, T ...>
{
    static const int Head = head;
    using Tail = IntList<T ...>;
};

template <>
struct IntList<>
{
};

template <typename L>
struct Length
{
    static const int value = Length<typename L::Tail>::value + 1;
};

template <>
struct Length<IntList<>>
{
    static const int value = 0;
};

//template <typename T>
//struct Length;
//
//template<template<int ...> class IntList, int ...Values>
//struct Length<IntList<Values...>>
//{
//    static const int value = sizeof...(Values);
//};

template <int, typename L>
struct IntCons
{
};

template <int head, int ... tail>
struct IntCons<head, IntList<tail...>>
{
    using type = IntList<head, tail...>;
};

template <typename L1, typename L2>
struct Concat;

template <int ... l1, int ... l2>
struct Concat<IntList<l1...>, IntList<l2...>>
{
    using type = IntList<l1..., l2...>;
};

template <int N, int K = 0>
struct Generate
{
//    using type = typename Concat<IntList<K>, typename Generate<N - 1, K + 1>::type>::type;
    using type = typename IntCons<K, typename Generate<N - 1, K + 1>::type>::type;
};

template <int K>
struct Generate<0, K>
{
    using type = IntList<>;
};

template <class L>
void Print()
{
    std::cout << L::Head << " ";
    Print<typename L::Tail>();
}

template <>
void Print<IntList<>>()
{
    std::cout << std::endl;
}

template <typename T, int ... index>
void PrintTupleImpl(T&& t, IntList<index...> list)
{
    ((std::cout << std::get<index>(t) << " "), ...);
};

template <typename ... Args>
void PrintTuple(std::tuple<Args...> t)
{
    PrintTupleImpl(std::move(t), typename Generate<sizeof...(Args)>::type {});
};

template <typename F, typename T, int ... index>
auto apply_impl(const F& f, T&& t, IntList<index...> list)// -> decltype(f(std::get<index>(t)...))
{
    return f(std::get<index>(t)...);
};

template <typename F, typename ... Args>
auto apply(F f, std::tuple<Args...> t)// -> decltype (apply_impl(f, t, typename Generate<sizeof...(Args)>::type {}))
{
    return apply_impl(f, std::move(t), typename Generate<sizeof...(Args)>::type {});
};

//template <typename F, typename ... Ts>
//auto apply(F&& f, std::tuple<Ts...> t)
//{
//    const auto size = sizeof...(Ts);
//
//    using List = typename Generate<size>::type;
//
//    return apply_impl(f, t, List {});
//};


template <typename L1, typename L2, template <int, int> class MF>
struct Zip;

template <int ... items1, int ... items2, template <int, int> class MF>
struct Zip<IntList<items1...>, IntList<items2...>, MF>
{
    using type = IntList<MF<items1, items2>::value...>;
};

template <typename L1, typename L2, template <int, int> class MF>
using zip_t = Zip<L1, L2, MF>;

//template <typename L1, typename L2, template <int, int> class MF>
//struct Zip
//{
//    using type = typename IntCons<MF<L1::Head, L2::Head>::value,
//                                  typename Zip<typename L1::Tail,
//                                               typename L2::Tail,
//                                               MF>::type>::type;
//};
//
//
//template <template <int, int> class MF>
//struct Zip<IntList<>, IntList<>, MF>
//{
//    using type = IntList<>;
//};
//
//