#include "Brass.h"

//typedef ios_base::fmtflags format;
//typedef streamsize precis;
//format setFormat();
//void restore(format f, precis p);



Brass::Brass(const string& s, long an, double bal)
{
	this->fullName = s;
	this->acctNum = an;
	this->balance = bal;

}


void Brass::Deposit(double amt)
{
	if (amt < 0)
	{
		cout << "Negative deposit not allowed;"
			<< "deposit is cancelled.\n";
	}
	else
	{
		this->balance += amt;
	}
	

}


void Brass::Withdraw(double amt)
{
	//format initialState = setFormat();
	//precis prec = cout.precision(2);

	if (amt < 0)
	{
		cout << "Withdrawal amount must be positive;"
			<< "withdrawal canceled.\n";
	}
	else if (amt <= this->balance)
	{
		this->balance -= amt;
	}
	else
	{
		cout << "Withdrawal amount of $" << amt
			<< " exceeds your balance.\n"
			<< "Withdrawal canceled.\n";
	}

	//restore(initialState, prec);
}


double Brass::Banlance()const
{
	
	return this->balance;

}


void Brass::ViewAcct() const
{
	//format initialState = setFormat();
	//precis prec = cout.precision(2);

	cout << "Client: " << this->fullName << endl;
	cout << "Account Number: " << this->acctNum << endl;
	cout << "Balance: $" << this->balance << endl;

	//restore(initialState, prec);
}


/*format setFormat()
{
	return cout.setf(ios_base::fixed, ios_base::floatfield);
}


void restore(format f, precis p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}*/