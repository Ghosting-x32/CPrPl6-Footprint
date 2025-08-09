#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"abstr_emp.h"
#include"fink.h"
#include"manager.h"

using namespace std;

class highfink : public fink, public manager
{
public:
	highfink();
	highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico);
	highfink(const abstr_emp& e, const string& rpo, int ico);
	highfink(const highfink& e);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const string& rpo);

	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall()const;

	friend ostream& operator<<(ostream& os, const highfink& e);

};
