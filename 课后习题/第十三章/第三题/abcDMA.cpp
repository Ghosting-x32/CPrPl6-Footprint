#include"abcDMA.h"

abcDMA::abcDMA(const char* l, int r)
{
	this->label = new char[strlen(l) + 1];
	strncpy_s(this->label, strlen(l) + 1, l, strlen(l));
	this->rating = r;
}


abcDMA::abcDMA(const abcDMA& rs)
{
	this->label = new char[strlen(rs.label) + 1];
	strncpy_s(this->label, strlen(rs.label) + 1, rs.label, strlen(rs.label));

	this->rating = rs.rating;
}


abcDMA::~abcDMA()
{
	if (this->label != NULL)
	{
		delete[] this->label;
		this->label = NULL;
	}

}


abcDMA& abcDMA::operator= (const abcDMA& rs)
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


void abcDMA::View()
{
	cout << "Label: " << this->label << endl;
	cout << "Rating: " << this->rating << endl;

}