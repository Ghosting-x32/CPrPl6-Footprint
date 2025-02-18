#include<cstring>
#include"string1.h"
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}


String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

char& String::operator[](int n)
{
	return str[n];
}

const char& String::operator[](int n)const
{
	return str[n];
}

bool operator<(const String& st, const String& st1)
{
	return (std::strcmp(st.str, st1.str) < 0);
}

bool operator>(const String& st, const String& st1)
{
	return st1 < st;
}

bool operator==(const String& st, const String& st1)
{
	return (std::strcmp(st.str, st1.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}