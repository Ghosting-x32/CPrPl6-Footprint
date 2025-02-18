#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>


class complex
{
private:
	double sisu;
	double xusu;
public:
	complex();
	complex(double t1, double t2);
	~complex();
	void setco(double t1 = 0.0, double t2 = 0.0);
	complex operator+(const complex& st)const;
	complex operator-(const complex& st)const;
	complex operator*(const complex& st)const;
	complex operator*(double n)const;
	friend complex operator*(double n, const complex& st);
	complex operator~()const;
	friend std::ostream& operator<<(std::ostream& os, const complex& st);
	friend std::istream& operator>>(std::istream& is, complex& st);
};

























#endif 
