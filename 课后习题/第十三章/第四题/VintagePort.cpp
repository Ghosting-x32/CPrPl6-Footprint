#include"VintagePort.h"

VintagePort::VintagePort(const char* ni, int y, const char* br, const char* st, int b)
	:Port(br, st, b)
{
	this->nickname = new char[strlen(ni) + 1];
	strncpy_s(this->nickname, strlen(ni) + 1, ni, strlen(ni));

	this->year = y;
}


VintagePort::VintagePort(const VintagePort& vi)
	:Port(vi)
{
	this->nickname = new char[strlen(vi.nickname) + 1];
	strncpy_s(this->nickname, strlen(vi.nickname) + 1, vi.nickname, strlen(vi.nickname));


	this->year = vi.year;
}


VintagePort::~VintagePort()
{
	if (this->nickname != NULL)
	{
		delete[] this->nickname;
		this->nickname = NULL;

	}

}


VintagePort& VintagePort::operator=(const VintagePort& vi)
{
	if (this == &vi)
	{
		return *this;
	}

	Port::operator=(vi);

	if (this->nickname != NULL)
	{
		delete[] this->nickname;
		this->nickname = NULL;

	}
	this->nickname = new char[strlen(vi.nickname) + 1];
	strncpy_s(this->nickname, strlen(vi.nickname) + 1, vi.nickname, strlen(vi.nickname));


	this->year = vi.year;



	return *this;
}


void VintagePort::Show()const
{
	Port::Show();
	cout << "Nickname: " << this->nickname << endl;
	cout << "Year: " << this->year << endl;

}


ostream& operator<<(ostream& os, const VintagePort& p)
{
	os << (const Port&)p;
	os << p.nickname << ", " << p.year << endl;
	return os;
}