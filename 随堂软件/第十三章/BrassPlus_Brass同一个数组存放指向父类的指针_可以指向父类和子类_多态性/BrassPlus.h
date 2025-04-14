#ifndef BRASSPLUS_H_
#define BRASSPLUS_H_
#include<iostream>
#include<string>

#include"Brass.h"

using namespace std;

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;

public:
	BrassPlus(const string& s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;

	void ResetMax(double m) { this->maxLoan = m; }
	void ResetRate(double r) { this->rate = r; }
	void ResetOwes() { this->owesBank = 0; }
};





#endif 

