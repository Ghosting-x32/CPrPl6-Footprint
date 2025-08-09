#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"abstr_emp.h"

using namespace std;

class fink : virtual public abstr_emp
{
private:

	string reportsto;


protected:
	const string ReportsTo()const;
	string& ReportsTo();



public:
	fink();
	fink(const string& fn, const string& ln, const string& j, const string& rpo);
	fink(const abstr_emp& e, const string& rpo);
	fink(const fink& e);

	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall()const;

	friend ostream& operator<<(ostream& os, const fink& e);

};
