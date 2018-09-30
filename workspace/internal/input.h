#pragma once

#include <iostream>
#include "../study/strings.h"

namespace util
{

template <class T>
T Input()
{
    T x = {};
    std::cin >> x;
    return x;
}

template <>
char* Input<char*>()
{
    if (std::cin.peek() == '\n')
        std::cin.ignore();
    return study::InputChars();
}

} // namespace util