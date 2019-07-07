#include "strings.h"

#include "allocate.h"

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

size_t Length(const char* str)
{
    size_t len = 0;
    while (str[len++]);
    return len - 1;
}

const char* End(const char* str)
{
    while (*str) ++str;
    return str;
}

char* End(char* str)
{
    while (*str) ++str;
    return str;
}

void StrCat(char* str1, const char* str2)
{
    for (str1 = End(str1); !*str2; )
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

bool Compare(const char* text, const char* pattern)
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

//StrStr
int Find(const char* text, const char* pattern)
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
    const auto factor = 2;
    char* result = new char[reservedSize];

    char symbol = '\0';
    size_t index = 0;
    while (std::cin.get(symbol) && symbol != '\n')
    {
        if (index >= reservedSize - 1)
        {
            result = study::resize(result, reservedSize, reservedSize * factor);
            reservedSize *= factor;
        }
        result[index] = symbol;
        ++index;
    }
    result[index] = '\0';

    return result;
}

String::String(const char* str_)
    : m_size {Length(str_)}
    , m_data {strcpy(new char[m_size + 1], str_ )}
    // TODO strcpy
{}

String::String(size_t count, char symbol)
    : m_size {count}
    , m_data  {new char[m_size + 1]}
{
    m_data[m_size] = '\0';

    while (count--)
        m_data[count] = symbol;
}

String::~String()
{
    delete [] m_data;
}

void String::Swap(String& rhs)
{
    if (this == &rhs)
        return;

    util::Swap(m_size, rhs.m_size);
    util::Swap(m_data, rhs.m_data);
}

String& String::operator=(const String& rhs)
{
    if (this != &rhs)
        String(rhs).Swap(*this);

    return *this;
}

String& String::Append(const String& rhs)
{
    auto size_new = m_size + rhs.m_size;
    auto str_new = new char[size_new + 1];

    strcpy(str_new, m_data);
    strcpy(str_new + m_size, rhs.m_data);

    delete [] m_data;

    m_size = size_new;
    m_data = str_new;

    return *this;
}

size_t String::size() const
{
    return m_size;
}

char* const String::get() const
{
    return m_data;
}

} // namespace study