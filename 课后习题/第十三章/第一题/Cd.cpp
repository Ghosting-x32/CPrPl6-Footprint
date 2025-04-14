#include"Cd.h"

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strncpy_s(this->performers, 50, s1, 49);
	strncpy_s(this->label, 20, s2, 19);

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


