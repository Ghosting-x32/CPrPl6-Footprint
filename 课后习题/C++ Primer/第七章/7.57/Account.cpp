#include"Account.h"


double Account::interestRate = initRate();
constexpr int Account::period;

void Account::rate(double newRate)
{
	interestRate = newRate;

}

double Account::initRate()
{
	double temp = 3.14;

	return temp;

}

