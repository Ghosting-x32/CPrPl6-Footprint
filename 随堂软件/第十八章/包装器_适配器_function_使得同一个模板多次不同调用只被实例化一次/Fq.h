#pragma once
#include<iostream>


class Fq
{
private:

	double z_;


public:
	Fq(double z = 1.0);
	double operator()(double q);




};