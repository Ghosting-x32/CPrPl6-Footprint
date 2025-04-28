#include"Card.h"

Card::Card(const string& hs, int mz)
	:m_Huase(hs)
{
	this->m_Mianzhi = mz;

}

void Card::view()const
{
	cout << this->m_Huase  << "->" << this->m_Mianzhi;

}

const string& Card::viewhs()const
{
	return this->m_Huase;

}


const int& Card::viewmz()const
{
	return this->m_Mianzhi;

}