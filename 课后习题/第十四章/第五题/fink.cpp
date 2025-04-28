#include"fink.h"


fink::fink()
	:abstr_emp(), reportsto()
{
	

}


fink::fink(const string& fn, const string& ln, const string& j, const string& rpo)
	:abstr_emp(fn, ln, j), reportsto(rpo)
{


}


fink::fink(const abstr_emp& e, const string& rpo)
	:abstr_emp(e), reportsto(rpo)
{


}


fink::fink(const fink& e)
	:abstr_emp(e), reportsto(e.reportsto)
{


}


void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "reportsto: " << this->reportsto << endl;

}


void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "������reportsto: ";
	cin >> this->reportsto;

}


const string fink::ReportsTo()const
{
	return this->reportsto;

}


string& fink::ReportsTo()
{
	return this->reportsto;

}


ostream& operator<<(ostream& os, const fink& e)
{
	os << (const abstr_emp&)e;//os << e;//----ָ�����ָ������ÿ���ָ������������Ի���������д
	os << "reportsto: " << e.reportsto << endl;
	return os;
}