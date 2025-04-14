#include"Classic.h"

Classic::Classic(const char* m, const char* s1, const char* s2, int n, double x)
	:Cd(s1, s2, n, x)
{
	strncpy_s(this->Main_works, 50, m, 49);

}



void Classic::Report()const
{
	Cd::Report();
	cout << "Main_works: " << this->Main_works << endl;

}