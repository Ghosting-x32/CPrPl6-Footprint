#include"Customer.h"

Customer::Customer()
{
	this->processtime = 0;
	this->arrive = 0;

}


long Customer::when() const
{
	return this->arrive;

}


int Customer::ptime() const
{
	return this->processtime;

}


void Customer::set(long when)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dis(1, 3);

	this->processtime = dis(gen);
	this->arrive = when;
}