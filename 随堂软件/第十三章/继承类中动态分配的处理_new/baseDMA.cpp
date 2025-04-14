#include"baseDMA.h"

baseDMA::baseDMA(const char* l, int r)
{
	this->label = new char[strlen(l) + 1];
	strcpy_s(this->label, strlen(l) + 1, l);
	this->rating = r;
}


baseDMA::baseDMA(const baseDMA& rs)
{
	this->label = new char[strlen(rs.label) + 1];
	strncpy_s(this->label, strlen(rs.label) + 1, rs.label, strlen(rs.label));

	this->rating = rs.rating;
}


baseDMA::~baseDMA()
{
	if (this->label != NULL)
	{
		delete[] this->label;
		this->label = NULL;
	}

}


baseDMA& baseDMA::operator= (const baseDMA& rs)
{
	if (this == &rs)
	{
		return *this;
	}

	if (this->label != NULL)
	{
		delete[] this->label;
		this->label = NULL;
	}
	
	this->label = new char[strlen(rs.label) + 1];
	strncpy_s(this->label, strlen(rs.label) + 1, rs.label, strlen(rs.label));

	this->rating = rs.rating;

	return *this;
}


ostream& operator<<(ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}