#include <cstring>
#include <iostream>
#include "internal/io.h"

class String
{
public:
	String(const char *str = "");
	String(size_t n, char c);
	~String() = default;

	String CreateStringForSecondBrace(const String& rhs, size_t shift) const;

    String(const String &other)
   	    : String(other.str) {}

    String &operator=(const String &other);

    void append(const String &other);
    char* const get() const {return str;}
    size_t length() const {return size;};

    String SubString(size_t i, size_t j) const;

    String operator[](const size_t pos) const;

private:
	size_t size = 0;
	char *str = "";

public:
    void SetBraceForSuffix(bool braceForSuffix_) {braceForSuffix = braceForSuffix_;}
    void SetShift(size_t shift_) {shift = shift_;}

private:
    bool braceForSuffix = true;
	size_t shift = 0;
};

String::String(const char* str_)
    : size {strlen(str_)}
    , str {strcpy(new char[size + 1], str_ )}
{}

String String::CreateStringForSecondBrace(const String& rhs, size_t shift_) const
{
    String string(rhs.str);

    string.SetBraceForSuffix(false);
    string.SetShift(shift_);

    return string;
}

String String::SubString(size_t i, size_t j) const
{
    if (i >= j || j > length())
        return {};

    auto subLength = j - i;

    char data[subLength + 1];

    data[subLength] = '\0';

    strncpy(data, str + i, subLength);

    return String(data);
}

String String::operator[](const size_t pos) const
{
    if (braceForSuffix)
        return CreateStringForSecondBrace(SubString(pos, length()), pos);

    return SubString(0, pos - shift);
}

int main()
{
    String string = "abcdefgh";

    std::cout << string.get() << "\n";

    const auto sub = string[2][6];
    util::ShowType(sub);

    std::cout << sub.get() << "\n";

    util::PrintComplete();

}
