#pragma once
#include<iostream>
#include<string>

using namespace std;

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;



public:
	abstr_emp();
	abstr_emp(const string& fn, const string& ln, const string&j);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual ~abstr_emp() = 0;

	friend ostream& operator<<(ostream& os, const abstr_emp& e);
	
};
