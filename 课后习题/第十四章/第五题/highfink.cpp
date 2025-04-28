#include"highfink.h"

highfink::highfink()
	:abstr_emp(), manager(), fink()
{


}


highfink::highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico)
	:abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{


}


highfink::highfink(const abstr_emp& e, const string& rpo, int ico)
	:abstr_emp(e), manager(e, ico), fink(e, rpo)
{


}


highfink::highfink(const highfink& e)
	:abstr_emp(e), manager(e), fink(e)
{


}


highfink::highfink(const fink& f, int ico)
	:abstr_emp(f), manager(f, ico), fink(f)
{


}


highfink::highfink(const manager& m, const string& rpo)
	:abstr_emp(m), manager(m), fink(m, rpo)
{


}


void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "inchargeof: " << this->InChargeOf() << endl;
	cout << "reportsto: " << this->ReportsTo() << endl;

}


void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "ÇëÊäÈëinchargrof: ";
	while (!(cin >> this->InChargeOf()))
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


	cout << "ÇëÊäÈëreportsto: ";
	cin >> this->ReportsTo();
}


ostream& operator<<(ostream& os, const highfink& e)
{
	os << (const abstr_emp&)e;
	os << "inchargeof: " << e.InChargeOf() << endl;
	os << "reportsto: " << e.ReportsTo() << endl;
	return os;
}