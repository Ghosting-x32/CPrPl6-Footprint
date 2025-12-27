#pragma once
#include<string>
#include<iostream>

using std::string;
using std::cin;
using std::cout;
using std::end;


class Account
{
public:
	void calculate()
	{
		amount += amount * interestRate;
	}

	static double rate()
	{
		return interestRate;
	}

	static void rate(double newRate);



private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;
	double daily_tbl[period];

};
