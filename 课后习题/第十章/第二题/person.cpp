#include<iostream>
#include"person.h"

Person::Person()
{
	lname = "";
	fname[0] = '\0';
}

Person::Person(const std::string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, fn);
}

Person::~Person()
{
}

void Person::Show()const
{
	std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow()const
{
	std::cout << lname << ", " << fname << std::endl;
}