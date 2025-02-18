#include<iostream>
#include"plorg.h"

Plorg::Plorg(const char ar[], int n)
{
	strcpy_s(name, ar);
	CI = n;
}

Plorg::~Plorg()
{
}

void Plorg::gnexi(int n)
{
	this->CI = n;
}

void Plorg::show()
{
	using std::cout;
	using std::endl;
	cout << "name: " << this->name << endl;
	cout << "CI: " << this->CI << endl;
}