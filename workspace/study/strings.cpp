#include "memory.h"

#include <iostream>

namespace study
{

void TrimSpacesInStream()
{
    char symbol = '\0';
    bool isSpaceBefore = false;
    while (std::cin.get(symbol))
    {
        if (symbol != ' ' || !isSpaceBefore)
            std::cout << symbol;

        isSpaceBefore = symbol == ' ';
    }
}

size_t length(const char* str)
{
    size_t len = 0;
    while (str[len++]);
    return len - 1;
}

const char* end(const char* str)
{
    while (*str) ++str;
    return str;
}

char* end(char* str)
{
    while (*str) ++str;
    return str;
}

void strcat(char* str1, const char* str2)
{
    for (str1 = end(str1); !*str2; )
        *str1++ = *str2++;
    *str1 = '\0';

}

//void strcat(char* str1, const char* str2)
//{
//    str1 += length(str1);
//    while (*str2)
//        *str1++ = *str2++;
//    *str1 = '\0';
//}

//void strcat(char* str1, const char* str2)
//{
//    while (*str1) str1++;
//    while (*str1++ = *str2++);
//}

bool compare(const char* text, const char* pattern)
{
    while (*pattern)
        if (*text++ != * pattern++)
            return false;
    return true;
}

//int strstr(const char* text, const char* pattern)
//{
//    for (int index = 0; index <= length(text) - length(pattern); ++index)
//    {
//        if (compare(text + index, pattern))
//            return index;
//    }
//    return -1;
//}

int strstr(const char* text, const char* pattern)
{
//    if (!*text)
//        return - 1;

    int index = 0;
    const char* pText = text;
    const char* pPattern = pattern;

    while (*pPattern)
    {
        if (!*pText)
            return -1;

        if (*pText++ != *pPattern++)
        {
            ++index;
            pText = text + index;
            pPattern = pattern;
        }
    }
    return index;
}

char* InputChars()
{
    size_t reservedSize = 16;
    char* result = new char[reservedSize];

    char symbol = '\0';
    size_t index = 0;
    while (std::cin.get(symbol) && symbol != '\n')
    {
        if (index >= reservedSize - 1)
        {
            result = study::resize(result, reservedSize, reservedSize * 2);
            reservedSize *= 2;
        }

        result[index] = symbol;
        ++index;
    }
    result[index] = '\0';

    return result;
}

} // namespace study