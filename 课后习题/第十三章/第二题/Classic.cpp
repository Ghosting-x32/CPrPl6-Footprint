#include"Classic.h"

Classic::Classic(const char* m, const char* s1, const char* s2, int n, double x)
	:Cd(s1, s2, n, x)
{
	this->Main_works = new char[strlen(m) + 1];

	strncpy_s(this->Main_works, strlen(m) + 1, m, strlen(m));

}



void Classic::Report()const
{
	Cd::Report();
	cout << "Main_works: " << this->Main_works << endl;

}

Classic::Classic(const Classic& clic)
	:Cd(clic)
{
	this->Main_works = new char[strlen(clic.Main_works) + 1];

	strncpy_s(this->Main_works, strlen(clic.Main_works) + 1, clic.Main_works, strlen(clic.Main_works));

}


Classic::~Classic()
{
	if (this->Main_works != NULL)
	{
		delete[] this->Main_works;
		this->Main_works = NULL;
	}

}


Classic& Classic::operator=(const Classic& clic)
{
	if (this == &clic)
	{
		return *this;
	}

	Cd::operator=(clic);

	if (this->Main_works != NULL)
	{
		delete[] this->Main_works;
		this->Main_works = NULL;
	}
	this->Main_works = new char[strlen(clic.Main_works) + 1];

	strncpy_s(this->Main_works, strlen(clic.Main_works) + 1, clic.Main_works, strlen(clic.Main_works));

	return *this;
}