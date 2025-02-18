#include<iostream>
#include<cstring>
#include"stock10.h"

Stock::Stock()
{
	std::cout << "Default constructor called\n";
	company = new char[1];
	company[0] = '0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	company = new char[std::strlen(co) + 1];
	strcpy_s(company, std::strlen(co) + 1, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock(const Stock& sr)
{
	company = new char[std::strlen(sr.company) + 1];
	strcpy_s(company, std::strlen(sr.company) + 1, sr.company);
	shares = sr.shares;
	share_val = sr.share_val;
	total_val = sr.total_val;
}

Stock::~Stock()
{
	std::cout << "Bye, " << company << "!\n";
	delete[] company;
}

Stock& Stock::operator=(const Stock& sr)
{
	company = new char[std::strlen(sr.company) + 1];
	strcpy_s(company, std::strlen(sr.company) + 1, sr.company);
	shares = sr.shares;
	share_val = sr.share_val;
	total_val = sr.total_val;
	return *this;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sel more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

std::ostream& operator<<(std::ostream& os, Stock& sr)
{
	using std::ios_base;
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << sr.company
		<< " Shares: " << sr.shares << '\n'
		<< " Share Price: $" << sr.share_val;
	os.precision(2);
	os << " Total Worth: $" << sr.total_val << '\n';
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}