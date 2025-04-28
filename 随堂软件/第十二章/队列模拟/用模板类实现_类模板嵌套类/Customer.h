#pragma once
#include<iostream>
#include<string>
#include<random>


using namespace std;

class Customer
{
private:
	long arrive;
	int processtime;

public:
	Customer();
	void set(long when);
	long when() const;
	int ptime() const;
};



