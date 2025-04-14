#include"hasDMA.h"

hasDMA::hasDMA(const char* s, const char* l, int r)
	:abcDMA(l, r)
{
	this->style = new char[strlen(s) + 1];
	strncpy_s(this->style, strlen(s) + 1, s, strlen(s));

}


hasDMA::hasDMA(const hasDMA& hs)
	:abcDMA(hs)
{
	this->style = new char[strlen(hs.style) + 1];
	strncpy_s(this->style, strlen(hs.style) + 1, hs.style, strlen(hs.style));
}


hasDMA::hasDMA(const char* s, const abcDMA& rs)
	:abcDMA(rs)
{
	this->style = new char[strlen(s) + 1];
	strncpy_s(this->style, strlen(s) + 1, s, strlen(s));

}


hasDMA::~hasDMA()
{
	if (this->style != NULL)
	{
		delete[] this->style;
		this->style = NULL;
	}

}


hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	
	if (this == &rs)
	{
		return *this;
	}
	//*this = rs;
	abcDMA::operator=(rs);
	if (this->style != NULL)
	{
		delete[] this->style;
		this->style = NULL;
	}

	this->style = new char[strlen(rs.style) + 1];
	strncpy_s(this->style, strlen(rs.style) + 1, rs.style, strlen(rs.style));
	return *this;
}


void hasDMA::View()
{
	abcDMA::View();
	cout << "Style: " << this->style << endl;

}




