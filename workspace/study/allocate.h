#include <cstdlib>
#include <iostream>

namespace study
{

char *resize(const char *str, size_t size, size_t size_new)
{
    char* str_new = new char[size_new];

    if (size_new < size)
        size = size_new;
    for (size_t index = 0; index < size; ++index)
        str_new[index] = str[index];

    delete [] str;
    str = nullptr;

    return str_new;
}

} // namespace study