#include"stonewt.h"

Stonewt::Stonewt(double lbs, stzt stzt2)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	stzt1 = stzt2;
}

Stonewt::Stonewt(int stn, double lbs, stzt stzt2)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	stzt1 = stzt2;
}

Stonewt::Stonewt()
{
	stone = pds_left = pounds = 0;
	stzt1 = Dpounds;
}

Stonewt::~Stonewt()
{
}

Stonewt Stonewt::operator+(const Stonewt& st)const
{
	return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& st)const
{
	return Stonewt(pounds - st.pounds);
}

Stonewt Stonewt::operator*(double n)const
{
	return Stonewt(pounds * n);
}

Stonewt operator*(double n, const Stonewt& st)
{
	return st * n;
}

void Stonewt::setstztIS()
{
	stzt1 = Istone;
}

void Stonewt::setstztIP()
{
	stzt1 = Ipounds;
}

void Stonewt::setstztDP()
{
	stzt1 = Dpounds;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& ts)
{
	if (ts.stzt1 == Stonewt::Istone)
		os << ts.stone << " stone, " << ts.pds_left << " pounds.\n";
	else if (ts.stzt1 == Stonewt::Ipounds)
		os << int(ts.pounds) << " pounds.\n";
	else if (ts.stzt1 == Stonewt::Dpounds)
		os << ts.pounds << " pounds.\n";
	else
		os << "状态成员不正确！\a\a\n";
	return os;
}

