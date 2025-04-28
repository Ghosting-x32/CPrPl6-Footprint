#include"manager.h"


manager::manager()
	:abstr_emp()
{
	this->inchargeof = 0;

}


manager::manager(const string& fn, const string& ln, const string& j, int ico)
	:abstr_emp(fn, ln, j)
{
	this->inchargeof = ico;

}


manager::manager(const abstr_emp& e, int ico)
	:abstr_emp(e)
{

	this->inchargeof = ico;
}


manager::manager(const manager& m)
	:abstr_emp(m)
{
	this->inchargeof = m.inchargeof;

}


void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "inchargeof: " << this->inchargeof << endl;

}


void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "ÇëÊäÈëinchargrof: ";
	while (!(cin >> this->inchargeof))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Incorrect input, please enter a number!" << endl;
	}


	while (cin.get() != '\n')
	{
		continue;
	}
}


int manager::InChargeOf()const
{
	return this->inchargeof;

}


int& manager::InChargeOf()
{
	return this->inchargeof;

}


ostream& operator<<(ostream& os, const manager& e)
{
	os << (const abstr_emp&)e;
	os << "inchargeof: " << e.inchargeof << endl;
	return os;
}