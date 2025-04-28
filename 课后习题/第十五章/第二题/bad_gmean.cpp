#include"bad_gmean.h"


bad_gmean::bad_gmean(double a, double b, const string& s)
	:logic_error(s)
{
	this->v1 = a;
	this->v2 = b;

}


const char* bad_gmean::mesg()
{
	return "\ngmean() arguments should be >= 0\n";

}