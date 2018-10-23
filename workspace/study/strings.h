#pragma once

#include "../internal/utility.h"

// TODO realize strcpy
#include <cstring>

namespace study
{

void TrimSpacesInStream();

size_t Length(const char* str);

const char* End(const char* str);

void StrCat(char* str1, const char* str2);

bool Compare(const char* text, const char* pattern);

// StrStr
int Find(const char* text, const char* pattern);

char* InputChars();

struct String
{
	String(const char *str_ = "");

    String(size_t count, char symbol);

	String(const String &rhs)
	    : String(rhs.m_data) {}

    ~String();

    void Swap(String& rhs);
    String& operator=(const String& rhs);

    String& Append(const String& rhs);

	size_t size() const;
	char* const get() const;

	operator const char* () const
	{
		return get();
	}
	
    size_t m_size = 0;
	char* m_data = nullptr;
};

} // namespace study