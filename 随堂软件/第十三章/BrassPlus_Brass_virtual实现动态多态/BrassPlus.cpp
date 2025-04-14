#include"BrassPlus.h"

//typedef ios_base::fmtflags format1;
//typedef streamsize precis1;
//format1 setFormat1();
//void restore1(format1 f, precis1 p);

BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r)
	:Brass(s, an, bal)
{
	this->maxLoan = ml;
	this->rate = r;
	this->owesBank = 0.0;

}


BrassPlus::BrassPlus(const Brass& ba, double ml, double r)
	:Brass(ba)
{
	this->maxLoan = ml;
	this->rate = r;
	this->owesBank = 0.0;

}


void BrassPlus::Withdraw(double amt)
{
	//format1 initialState = setFormat1();
	//precis1 prec = cout.precision(2);

	double bal = this->Banlance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + this->maxLoan - this->owesBank)
	{
		double advance = amt - bal;
		this->owesBank += advance * (1 + this->rate);
		cout << "Bank adcance: $" << advance << endl;
		cout << "Finance charge: $" << advance * this->rate << endl;
		this->Deposit(advance);
		Brass::Withdraw(amt);

	}
	else
	{
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	}

	//restore1(initialState, prec);
}


void BrassPlus::ViewAcct() const
{
	//format1 initialState = setFormat1();
	//precis1 prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximum loan: $" << this->maxLoan << endl;
	cout << "Owed to bank: $" << this->owesBank << endl;
	cout << "Loan Rate: " << 100 * this->rate << "%\n";

	//restore1(initialState, prec);
}

/*format1 setFormat1()
{
	return cout.setf(ios_base::fixed, ios_base::floatfield);
}


void restore1(format1 f, precis1 p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}*/