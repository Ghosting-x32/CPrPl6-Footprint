#pragma once
#include<iostream>
#include<string>
#include<random>

#include"Person.h"


using namespace std;

class Gunslinger : virtual public Person
{
private:

	int m_Numkh;
	


protected:

	const int& viewkh()const;

public:

	Gunslinger(int num = 0, const string& xi = "none", const string& mi = "none");
	double Draw()const;

	virtual void Show()const;
	virtual void Set();

};