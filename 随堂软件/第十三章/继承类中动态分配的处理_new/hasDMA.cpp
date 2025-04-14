#include"hasDMA.h"

hasDMA::hasDMA(const char* s, const char* l, int r)
	:baseDMA(l, r)
{
	this->style = new char[strlen(s) + 1];
	strcpy_s(this->style, strlen(s) + 1, s);

}


hasDMA::hasDMA(const hasDMA& hs)
	:baseDMA(hs)
{
	this->style = new char[strlen(hs.style) + 1];
	strncpy_s(this->style, strlen(hs.style) + 1, hs.style, strlen(hs.style));
}


hasDMA::hasDMA(const char* s, const baseDMA& rs)
	:baseDMA(rs)
{
	this->style = new char[strlen(s) + 1];
	strcpy_s(this->style, strlen(s) + 1, s);

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
	baseDMA::operator=(rs);
	if (this->style != NULL)
	{
		delete[] this->style;
		this->style = NULL;
	}

	this->style = new char[strlen(rs.style) + 1];
	strncpy_s(this->style, strlen(rs.style) + 1, rs.style, strlen(rs.style));
	return *this;
}




ostream& operator<<(ostream& os, const hasDMA& rs)
{
	os << (const baseDMA&)rs;
	os << "Style: " << rs.style << endl;
	return os;
}


