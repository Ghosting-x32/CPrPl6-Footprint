#include"Fp.h"

Fp::Fp(double z)
	:z_(z)
{


}

double Fp::operator()(double p)
{
	return z_ * p;

}