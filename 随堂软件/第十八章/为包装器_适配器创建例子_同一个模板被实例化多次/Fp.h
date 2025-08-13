#pragma once
#include<iostream>


class Fp
{
private:

	double z_;


public:
	Fp(double z = 1.0);

	double operator()(double p);

};
