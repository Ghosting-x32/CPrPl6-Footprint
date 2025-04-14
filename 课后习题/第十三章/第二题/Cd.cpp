#include"Cd.h"

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	this->performers = new char[strlen(s1) + 1];
	strncpy_s(this->performers, strlen(s1) + 1, s1, strlen(s1));

	this->label = new char[strlen(s2) + 1];
	strncpy_s(this->label, strlen(s2) + 1, s2, strlen(s2));

	this->playtime = x;
	this->selections = n;

}


void Cd::Report()const
{
	cout << "Performers: " << this->performers << endl;
	cout << "Label: " << this->label << endl;
	cout << "Selections: " << this->selections << endl;
	cout << "Playtime: " << this->playtime << endl;

}

Cd::Cd(const Cd& cd1)
{
	this->performers = new char[strlen(cd1.performers) + 1];
	strncpy_s(this->performers, strlen(cd1.performers) + 1, cd1.performers, strlen(cd1.performers));

	this->label = new char[strlen(cd1.label) + 1];
	strncpy_s(this->label, strlen(cd1.label) + 1, cd1.label, strlen(cd1.label));


	this->selections = cd1.selections;
	this->playtime = cd1.playtime;

}


Cd::~Cd()
{
	if (this->performers != NULL)
	{
		delete[] this->performers;
		this->performers = NULL;
	}

	if (this->label != NULL)
	{
		delete[] this->label;
		this->label = NULL;
	}

}


Cd& Cd::operator=(const Cd& cd1)
{
	if (this == &cd1)
	{
		return *this;
	}

	if (this->performers != NULL)
	{
		delete[] this->performers;
		this->performers = NULL;
	}
	this->performers = new char[strlen(cd1.performers) + 1];
	strncpy_s(this->performers, strlen(cd1.performers) + 1, cd1.performers, strlen(cd1.performers));



	if (this->label != NULL)
	{
		delete[] this->label;
		this->label = NULL;
	}
	this->label = new char[strlen(cd1.label) + 1];
	strncpy_s(this->label, strlen(cd1.label) + 1, cd1.label, strlen(cd1.label));

	this->selections = cd1.selections;
	this->playtime = cd1.playtime;
	return *this;
}
