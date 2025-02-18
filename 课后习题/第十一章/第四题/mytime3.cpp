#include"mytime3.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

Time::~Time()
{
}

void Time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::addHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& t, const Time& t1)
{
	Time sum;
	sum.minutes = t.minutes + t1.minutes;
	sum.hours = t.hours + t1.hours + sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}

Time operator-(const Time& t, const Time& t1)
{
	Time diff;
	int top1, top2;
	top1 = t.minutes + t.hours * 60;
	top2 = t1.minutes + t1.hours * 60;
	diff.hours = (top1 - top2) / 60;
	diff.minutes = (top1 - top2) % 60;
	return diff;
}

Time operator*(const Time& t, double n)
{
	Time result;
	long totalminutes = t.hours * 60 * n + t.minutes * n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes.";
	return os;
}
