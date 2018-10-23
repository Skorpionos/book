#pragma once

#include "../study/matrix.h"

#include "fmt/format.h"

//#include "../person.h"

#include <boost/type_index.hpp>

#include <map>
#include <queue>
#include <stack>

#include <iostream>
#include <iomanip>

namespace util
{

template <class T>
class _;

constexpr size_t breakStringSize = 70;
const auto headerString    = std::string(breakStringSize, '=').append("\n");
const auto separateString  = std::string(breakStringSize, '-').append("\n");

template<class T>
void ShowType()
{
//    std::cout << __PRETTY_FUNCTION__;
    using boost::typeindex::type_id_with_cvr;

    std::cout << "[" << sizeof(T) << "] ";
    std::cout << type_id_with_cvr<T>().pretty_name() << "\n";
}

template<class T>
void ShowType(T /*object*/)
{
    ShowType<T>();
}

template <class T> void PrintHeader(T container);

template <class T> void PrintContainer(T container);
template <class T, size_t N> void PrintContainer(T (&array) [N]) noexcept;
template <class T> void PrintContainer(const std::string& container);
template <class T> void PrintContainer(std::stack<T> container);
template <class T> void PrintContainer(std::queue<T> container);
template <class T> void PrintContainer(std::priority_queue<T> container);
template <class K, class V> void PrintContainer(std::map<K, V> container);

template <class T>
void PrintContainerInfo(T container)
{
    PrintHeader(container);

    PrintContainer(container);

    std::cout << separateString;
}

template<class T>
void PrintContainer(T container)
{
    std::cout << "[" << container.size() << "] ";
    for (const auto& element : container)
        std::cout << element << " ";
    std::cout << "\n";
}

template <class T>
void PrintContainer(std::queue<T> container)
{
    std::queue<T> copyContainer = container;
    while (!copyContainer.empty())
    {
        std::cout << copyContainer.front() << " ";
        copyContainer.pop();
    }
    std::cout << "\n";
};

template <class T>
void PrintContainer(std::priority_queue<T> container)
{
    std::priority_queue<T> copyContainer = container;
    while (!copyContainer.empty())
    {
        std::cout << copyContainer.top() << " ";
        copyContainer.pop();
    }
    std::cout << "\n";
};

template <class T>
void PrintContainer(std::stack<T> container)
{
    std::stack<T> copyContainer1 = container;
    std::stack<T> copyContainer2;
    while (!copyContainer1.empty())
    {
        copyContainer2.push(copyContainer1.top());
        copyContainer1.pop();
    }
    while (!copyContainer2.empty())
    {
        std::cout << copyContainer2.top() << " ";
        copyContainer2.pop();
    }

    std::cout << "\n";
};

template <class K, class V>
void PrintContainer(std::map<K, V> container)
{
    for (const auto& element : container)
    {
        std::cout << element.first << ", " << element.second << " ";
        std::cout << "\n";
    }
};

template<class T, size_t N>
void PrintContainer(T (&array) [N]) noexcept
{
    for (const auto& element : array)
        std::cout << element << " ";
    std::cout << "\n";
}
template <class T>
void PrintContainer(T array, size_t size) noexcept
{
    for (size_t index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << "\n";
}

//template <>
//void PrintContainer(std::vector<Person> container)
//{
//    for (const auto& person: container)
//        person.Print();
//};

template <class T>
void PrintHeader(T container)
{
    std::cout << "\n" << headerString;
    ShowType(container);
    std::cout <<" (" << sizeof(T) << "), size: " << container.size() << "\n";
    std::cout << separateString;

}

template <class T>
void Print(T object);
#include "print_impl.h"

//void Print() {}
template <class T, class ... Args>
void Print(const T& item, const Args& ... args)
{
    std::cout << " <" << sizeof...(args) << ">:" << item << " ";
    Print(args...);
}

template <class T, class ... Args>
void PrintLn(const T& item, const Args& ... args)
{
//    std::cout << "<" << sizeof...(args) << ":> ";
    std::cout << item << "\n";
    Print(args...);
}

template <class T>
void PrintContainer(const matrix::Matrix<T>& matrix)
{
    constexpr size_t Width = 5;

    std::cout << std::left;
    for (size_t row = 0; row < matrix.rows_count(); ++row)
    {
        for (size_t column = 0; column < matrix.columns_count(); ++column)
            std::cout << std::setw(Width) << matrix[row][column];
        std::cout << "\n";
    }
}

inline uint64_t ExtractVirtualTableAddress(const void* address)
{
    return *reinterpret_cast<const uint64_t*>(address);
}

inline void DebugAddress(size_t virtualTableAddress, size_t size)
{
    fmt::print("[{:#x}] ", virtualTableAddress);

    auto addressBegin = reinterpret_cast<const uint8_t*>(virtualTableAddress);

    for (size_t index = 0; index < size; ++index)
    {
        fmt::print("{:#x} ", *addressBegin);
        ++addressBegin;
    }
    fmt::print("\n");
}

//int main()
//{
//    const auto alexey = Man {"Alexey"};
//    const auto sergey = Person {"Sergey"};
//
//    alexey.Print();
//    sergey.Print();
//
//    util::DebugObject(alexey, sergey);
//
//    util::DebugAddress(util::ExtractVirtualTableAddress(&alexey), 20);
//    util::DebugAddress(util::ExtractVirtualTableAddress(&sergey), 20);
//}

inline void DebugObjectLine(size_t index) {}

template<class T, class ...Args>
void DebugObjectLine(size_t index, T object, Args ...objects)
{
    auto address     = static_cast<void*>(&object);
    auto addressByte = static_cast<uint8_t*>(address) + index;

    fmt::print("{}:{:#x}\t", static_cast<void*>(addressByte), *addressByte);

    // std::cout << " <" << sizeof...(objects) << ">:" << object << " ";

    DebugObjectLine(index, objects...);
}

template <class T, class ...Args>
void DebugObject(T object1, Args ...objects)
{
    auto size = sizeof(T);

    fmt::print("[{}]\n", size);

    // auto size = abs(static_cast<uint8_t*>(static_cast<void*>(&a2)) - static_cast<uint8_t*>(static_cast<void*>(&a1)));

    for (size_t index = 0; index < size; ++index)
    {
        DebugObjectLine(index, object1, objects...);

        fmt::print("\n");
    }
}

inline void PrintBreak(char symbol = '-', size_t count = 10)
{
    std::cout << std::string(count, symbol) << "\n";
}

inline void PrintComplete()
{
    PrintBreak('=');
    std::cout << "Completed." << "\n";
}

} // namespace util

namespace util::matrix
{

template <class T>
void Print(T** matrix, size_t N, size_t M)
{
    PrintContainer(matrix, N, M);
    util::PrintBreak();
}

template <class T>
void Print(const util::matrix::Matrix<T>& matrix)
{
    PrintContainer(matrix);
    util::PrintBreak();
}

}
// namespace util::matrix