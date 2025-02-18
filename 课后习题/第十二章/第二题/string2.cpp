#include<cstring>
#include"string2.h"
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

void String::stringlow()
{
	for (int i = 0; i < len; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
	{
		str[i] = toupper(str[i]);
	}
}

int String::has(const char a)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == a)
			sum++;
	}
	return sum;
}

String String::operator+(const String& st)
{
	String temp;
	temp.len = len + st.len;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, st.len + 1, str);
	strcat_s(temp.str, temp.len  + 1, st.str);
	return temp;
}

String operator+(const char* st1, const String& st)
{
	String temp;
	temp.len = std::strlen(st1) + st.len;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, std::strlen(st1) + 1, st1);
	strcat_s(temp.str, temp.len + 1, st.str);
	return temp;
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