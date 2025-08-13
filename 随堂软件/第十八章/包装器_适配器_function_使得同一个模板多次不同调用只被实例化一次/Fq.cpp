#include"Fq.h"

Fq::Fq(double z)
	:z_(z)
{


}


double Fq::operator()(double q)
{
	return z_ + q;

}