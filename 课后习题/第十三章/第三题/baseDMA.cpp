#include"baseDMA.h"

baseDMA::baseDMA(int text, const char* l, int r)
	:abcDMA(l, r)
{
	this->m_text = text;

}

void baseDMA::View()
{
	abcDMA::View();
	cout << "M_text: " << this->m_text << endl;

}