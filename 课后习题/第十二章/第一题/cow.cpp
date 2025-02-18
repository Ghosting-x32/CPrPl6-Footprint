#include<iostream>
#include<cstring>
#include"cow.h"
using std::cout;
using std::endl;


Cow::Cow()
{
	name[0] = '0';
	hobby = new char[1];
	hobby[0] = '0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, std::strlen(nm) + 1, nm);
	hobby = new char[std::strlen(ho) + 1];
	strcpy_s(hobby, std::strlen(ho) + 1, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, std::strlen(c.name) + 1, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	strcpy_s(hobby, std::strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	strcpy_s(name, std::strlen(c.name) + 1, c.name);
	delete[] hobby;
	hobby = new char[std::strlen(c.hobby) + 1];
	strcpy_s(hobby, std::strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	cout << "name: " << name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "weight: " << weight << endl;
}