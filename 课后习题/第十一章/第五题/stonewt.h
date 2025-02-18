#ifndef STONEWT_H_
#define STONEWT_H_
#include<iostream>



class Stonewt
{
public:
	enum stzt{Istone, Ipounds, Dpounds};

private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	stzt stzt1;

public:
	Stonewt(double lbs, stzt stzt2 = Dpounds);
	Stonewt(int stn, double lbs, stzt stzt2 = Dpounds);
	Stonewt();
	~Stonewt();
	Stonewt operator+(const Stonewt& st)const;
	Stonewt operator-(const Stonewt& st)const;
	Stonewt operator*(double n)const;
	void setstztIS();
	void setstztIP();
	void setstztDP();
	friend Stonewt operator*(double n, const Stonewt& st);
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& ts);
};






#endif