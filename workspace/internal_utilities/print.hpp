#pragma once

//#include "../person.h"

#include <boost/type_index.hpp>

#include <map>
#include <queue>
#include <stack>

#include <iostream>

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
template <class T, size_t N> void PrintContainer(T (&container) [N]) noexcept;
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

//template <>
//void PrintContainer(const std::string& container)
//{
//    std::cout << container << "\n";
//}

template<class T, size_t N>
void PrintContainer(T (&container) [N]) noexcept
{
    for (const auto& element : container)
        std::cout << element << " ";
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

#include "print_impl.hpp"

} // namespace internal_utilities