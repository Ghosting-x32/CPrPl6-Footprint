#include"Port.h"

Port::Port(const char* br, const char* st, int b)
{
	this->brand = new char[strlen(br) + 1];
	strncpy_s(this->brand, strlen(br) + 1, br, strlen(br));

	strncpy_s(this->style, strlen(st) + 1, st, strlen(st));
	this->bottles = b;

}


Port::Port(const Port& p)
{
	this->brand = new char[strlen(p.brand) + 1];
	strncpy_s(this->brand, strlen(p.brand) + 1, p.brand, strlen(p.brand));

	strncpy_s(this->style, strlen(p.style) + 1, p.style, strlen(p.style));

	this->bottles = p.bottles;

}


Port::~Port()
{
	if (this->brand != NULL)
	{
		delete[] this->brand;
		this->brand = NULL;
	}

}


Port& Port::operator=(const Port& p)
{
	if (this == &p)
	{
		return *this;
	}

	if (this->brand != NULL)
	{
		delete[] this->brand;
		this->brand = NULL;
	}
	this->brand = new char[strlen(p.brand) + 1];
	strncpy_s(this->brand, strlen(p.brand) + 1, p.brand, strlen(p.brand));

	strncpy_s(this->style, strlen(p.style) + 1, p.style, strlen(p.style));

	this->bottles = p.bottles;
	return *this;
}


Port& Port::operator+=(int b)
{
	this->bottles += b;
	return *this;

}


Port& Port::operator-=(int b)
{
	this->bottles -= b;
	return *this;

}


void Port::Show()const
{
	cout << "Brand: " << this->brand << endl;
	cout << "Kind: " << this->style << endl;
	cout << "Bottles: " << this->bottles << endl;

}


ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << endl;
	return os;
}