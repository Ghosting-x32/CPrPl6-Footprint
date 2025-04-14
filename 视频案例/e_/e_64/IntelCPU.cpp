#include"IntelCPU.h"
#include"Person.h"

bool IntelCPU::operator()(const Person& p1, const Person& p2)const
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Score < p2.m_Score;
	}
	else
	{
		return p1.m_Age > p2.m_Age;
	}
}
