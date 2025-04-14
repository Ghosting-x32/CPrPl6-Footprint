#include "lacksDMA.h"

lacksDMA::lacksDMA(const char* c, const char* l, int r)
	:abcDMA(l, r)
{
	strncpy_s(this->color, COL_LEN, c, COL_LEN - 1);

}


lacksDMA::lacksDMA(const char* c, const abcDMA& rs)
	:abcDMA(rs)
{
	strncpy_s(this->color, COL_LEN, c, COL_LEN - 1);

}

void lacksDMA::View()
{
	abcDMA::View();
	cout << "Color: " << this->color << endl;

}


