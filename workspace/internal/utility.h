#pragma once

namespace util
{

template<class T>
void swap(T& x, T& y)
{
    const auto temp = x;
    x = y;
    y = temp;
}

} // namespace util