#pragma once

#include <cstddef>
#include <tuple>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <functional>

namespace util
{

template<class T>
void Swap(T& x, T& y)
{
    const auto temp = x;
    x = y;
    y = temp;
}

template <class T, size_t N>
size_t ArraySize(T (& array)[N])
{
    return N;
}

template <class A, class B>
//auto Sum(A a, B b) -> decltype(a + b)
//auto Sum(A a, B b) // different rules for auto and decltype : ref, const
decltype(auto) Sum(A a, B b)
{
    return a + b;
}

template <int I1, int I2, class T>
//auto to_pair(T tuple) -> decltype(std::make_pair(std::get<I1>(tuple), std::get<I2>(tuple)))
auto to_pair(T tuple)
{
    return std::pair(std::get<I1>(tuple), std::get<I2>(tuple));
}

template <class T>
T Sum(std::initializer_list<T> list)
{
    T result {};
    for (const auto& item : list)
        result += item;
    return result;
}

template<class T, class F>
T* find_if(T* begin, T* end, F function)
{
    for (auto it = begin; it != end; ++it)
        if (function(*it))
            return it;
    return end;
}

template <class T>
using BinaryPredicate = const std::function<bool(T, T)>;

template <class T>
using UnaryPredicate = const std::function<bool(T)>;

template <class T>
T* Find(T* begin, T* end, UnaryPredicate<T> predicate)
{
    for (auto it = begin; it != end; ++it)
        if (predicate(*it))
                return it;
    return end;
}
//it = Find<int>(std::begin(array), std::end(array), [](int x){return x % 5 == 0;});

template <class T>
T* Find(T* begin, T* end, T value, BinaryPredicate<T> predicate)
{
    for (auto it = begin; it != end; ++it)
        if (predicate(*it, value))
                return it;
    return end;
}
//auto it = util::Find<int>(std::begin(array), std::end(array), 4, [](int x, int y){return x == y;});

//int main()
//{
//    int primes[5] = {2, 3, 5, 7, 11};
//
//    int m[10] = {0, 0, 1, 1, 4, 6, 7, 8, 9, 10};
//
//    auto gen_finder = [](const int* const begin, const int* const end){
//        return [begin, end](int x){
//            for (auto it = begin; it != end; ++it)
//                if (*it == x)
//                    return true;
//            return false;
//        };
//    };
//
////    auto gen_finder = [](int* begin, int* end) {
////        return [begin, end](int x) {
////            return find_if(begin, end, [x](int y) {return x == y;}) != end;
////        };
////    };
//
//    int* first_prime = find_if(std::begin(m), std::end(m),
//                               gen_finder(std::begin(primes) + 3, std::begin(primes) + 4));
//}


template <class F, class ... Args>
auto apply(F function, Args&& ... args)
{
    return function(std::forward<Args>(args)...);
}
//auto apply(F function, Args&& ... args) -> decltype(function(std::forward<Args>(args)...))

//auto fun = [](std::string a, std::string const& b) {
//    std::cout << a << "|" << b << "\n";
//    return a += b;
//};

class bad_from_string : public std::exception
{
public:
    bad_from_string(const char* info)
        : m_info(info)
    {}

    const char* what() const noexcept override
    {
        return m_info.c_str();
    }

private:
    std::string m_info;
};

template <class T>
T from_string(const std::string& arg)
{
    std::istringstream stream(arg);

    T result;

    stream >> std::noskipws >> result;

    if (stream.fail() || stream.peek() != EOF)
        throw bad_from_string("Argument is wrong!");

    return result;
}


} // namespace util