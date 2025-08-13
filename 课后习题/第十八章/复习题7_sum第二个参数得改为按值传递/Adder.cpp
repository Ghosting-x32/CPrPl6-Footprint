#include"Adder.h"

Adder::Adder(double q)
	:tot(q)
{

}

void Adder::operator()(double w)
{
	tot += w;
}

double Adder::tot_v()const
{
	return tot;
}
