#include"abstr_emp.h"

abstr_emp::abstr_emp()
	:fname(), lname(), job()
{


}


abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j)
	:fname(fn), lname(ln), job(j)
{



}


void abstr_emp::ShowAll()const
{
	cout << "fname: " << this->fname << "\tlname: " << this->lname << endl;
	cout << "job: " << this->job << endl;


}


void abstr_emp::SetAll()
{
	cout << "ÇëÊäÈëfname: ";
	cin >> this->fname;
	cout << "ÇëÊäÈëlname: ";
	cin >> this->lname;
	cout << "ÇëÊäÈëjob: ";
	cin >> this->job;


}


abstr_emp::~abstr_emp()
{


}


ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << "fname: " << e.fname << "\tlname: " << e.lname << endl;
	os << "job: " << e.job << endl;
	return os;
}


void abstr_emp::writeall()const
{
	ofstream fout;
	fout.open("dat.txt", ios_base::out | ios_base::app);
	fout << "fname: " << this->fname << "\tlname: " << this->lname << endl;
	fout << "job: " << this->job << endl;
	fout.close();
	
}