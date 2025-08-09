#include"employee.h"

employee::employee()
	:abstr_emp()
{


}


employee::employee(const string& fn, const string& ln, const string& j)
	:abstr_emp(fn, ln, j)
{



}


void employee::ShowAll()const
{
	abstr_emp::ShowAll();

}


void employee::SetAll()
{

	abstr_emp::SetAll();
}

ostream& operator<<(ostream& os, const employee& e)
{
	os << (const abstr_emp&)e;
	return os;
}

void employee::writeall()const
{
	abstr_emp::writeall();
	ofstream fout;
	fout.open("dat.txt", ios_base::out | ios_base::app);
	fout << "------------------------employee-----------------------" << endl;
	fout.close();
}