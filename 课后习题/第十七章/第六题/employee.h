#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"abstr_emp.h"

using namespace std;

class employee : public abstr_emp
{
public:
	employee();
	employee(const string& fn, const string& ln, const string& j);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall()const;

	friend ostream& operator<<(ostream& os, const employee& e);

};
