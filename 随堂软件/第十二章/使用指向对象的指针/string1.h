#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::ostream;
using std::istream;


class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String& st);
	~String();
	int length() { return len; };

	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int n);
	const char& operator[](int n)const;

	friend bool operator<(const String& st, const String& st1);
	friend bool operator>(const String& st, const String& st1);
	friend bool operator==(const String& st, const String& st1);
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is, String& st);

	static int HowMany();
};



#endif 
