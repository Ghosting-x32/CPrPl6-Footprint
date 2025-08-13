#include"f_mod.h"


f_mod::f_mod(int d)
	:dv(d)
{



}

bool f_mod::operator()(int n)
{
	return n % dv == 0;


}