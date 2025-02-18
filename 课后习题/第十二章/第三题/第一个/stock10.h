#ifndef STOCK10_H_
#define STOCK10_H_
#include<iostream>

class Stock
{
private:
	char* company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char* co, long n = 0, double pr = 0.0);
	Stock(const Stock& sr);
	~Stock();
	Stock& operator=(const Stock& sr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	friend std::ostream& operator<<(std::ostream& os, Stock& sr);
};

#endif