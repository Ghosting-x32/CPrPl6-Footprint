#include"bad_hmean.h"

bad_hmean::bad_hmean(double a, double b, const string& s)
	:logic_error(s)
{
	this->v1 = a;
	this->v2 = b;


}


void bad_hmean::mesg()
{
	cout << "\nhmean(" << this->v1 << ", " << this->v2 << "): " << "invalid arguments: a = -b\n";

}


double bad_hmean::givev1()
{

	return this->v1;
}


double bad_hmean::givev2()
{

	return this->v2;
}