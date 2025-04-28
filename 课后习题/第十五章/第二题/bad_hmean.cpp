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
