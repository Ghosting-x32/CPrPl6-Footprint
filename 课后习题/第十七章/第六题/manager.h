#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"abstr_emp.h"

using namespace std;

class manager : virtual public abstr_emp
{
private:
	int inchargeof;


protected:
	int InChargeOf()const;
	int& InChargeOf();



public:
	manager();
	manager(const string& fn, const string& ln, const string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);

	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall()const;

	friend ostream& operator<<(ostream& os, const manager& e);
};
