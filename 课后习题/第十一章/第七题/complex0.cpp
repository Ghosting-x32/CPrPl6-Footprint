#include"complex0.h"

complex::complex()
{
	sisu = xusu = 0.0;
}

complex::complex(double t1, double t2)
{
	sisu = t1;
	xusu = t2;
}

complex::~complex()
{
}

void complex::setco(double t1, double t2)
{
	sisu = t1;
	xusu = t2;
}

complex complex::operator+(const complex& st)const
{
	complex sum;
	sum.sisu = sisu + st.sisu;
	sum.xusu = xusu + st.xusu;	
	return sum;
}

complex complex::operator-(const complex& st)const
{
	complex sum1;
	sum1.sisu = sisu - st.sisu;
	sum1.xusu = xusu - st.xusu;
	return sum1;
}

complex complex::operator*(const complex& st)const
{
	complex sum2;
	sum2.sisu = sisu * st.sisu - xusu * st.xusu;
	sum2.xusu = sisu * st.xusu + xusu * st.sisu;
	return sum2;
}

complex complex::operator*(double n)const
{
	complex sum3;
	sum3.sisu = n * sisu;
	sum3.xusu = n * xusu;
	return sum3;
}

complex operator*(double n, const complex& st)
{
	return st * n;
}

complex complex::operator~()const
{
	complex sum4;
	sum4.sisu = sisu;
	sum4.xusu = -xusu;
	return sum4;
}

std::ostream& operator<<(std::ostream& os, const complex& st)
{
	os << "(" << st.sisu << ", " << st.xusu << "i)";
	return os;
}

std::istream& operator>>(std::istream& is, complex& st)
{
	std::cout << "real: ";
	is >> st.sisu;
	std::cout << "imaginary: ";
	is >> st.xusu;
	return is;
}