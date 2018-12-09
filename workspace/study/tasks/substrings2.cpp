#include <cstring>
#include <iostream>
#include "internal/io.h"

struct String
{
public:
	String(const char *str = "");
	String(size_t n, char c);
	~String() = default;

    String(const String &other)
   	    : String(other.str) {}

    String &operator=(const String &other);

    void append(const String &other);

    struct SubString;

    SubString operator[](size_t index1) const;

	size_t size = 0;
	char *str = nullptr;
};

String::String(const char* str_)
    : size {strlen(str_)}
    , str {strcpy(new char[size + 1], str_ )}
{}


struct String::SubString
{
    SubString(const String& str_, size_t shift_)
        : string(str_)
        , shift(shift_)
    {}

    String operator[](size_t index2) const
    {
        string.str[index2 - shift] = '\0';
        return String(string.str);
    }

    String string;
    size_t shift;
};

String::SubString String::operator[](size_t index1) const
{
    return String::SubString(String(str + index1), index1);
}

int main()
{
    String string = "abcdefgh";

    std::cout << string.str << "\n";

    const auto sub = string[7][8];
    util::ShowType(sub);

    std::cout << sub.str << "\n";

    util::PrintComplete();

}
