#include "lacksDMA.h"

lacksDMA::lacksDMA(const char* c, const char* l, int r)
	:baseDMA(l, r)
{
	strncpy_s(this->color, COL_LEN, c, COL_LEN - 1);

}


lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	:baseDMA(rs)
{
	strncpy_s(this->color, COL_LEN, c, COL_LEN - 1);

}


ostream& operator<<(ostream& os, const lacksDMA& rs)
{
	os << (const baseDMA&)rs;
	os << "Color: " << rs.color << endl;
	return os;

}

