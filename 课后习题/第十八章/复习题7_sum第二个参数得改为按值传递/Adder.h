#pragma once
#include<iostream>

using namespace std;

class Adder
{
private:

	double tot;

public:

	Adder(double q = 0);
	void operator()(double w);
	double tot_v()const;

};

