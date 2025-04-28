#include"bad_gmean.h"


bad_gmean::bad_gmean(double a, double b, const string& s)
	:bad_hmean(a, b, s)
{
	

}


void bad_gmean::mesg()
{
	cout << "\nv1 = " << bad_hmean::givev1() << " , v2 = " << bad_hmean::givev2() << endl;
	cout << "º¯ÊıÃûÊÇ: mesg" << endl;
}