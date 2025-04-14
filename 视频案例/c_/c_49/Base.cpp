#include"Base.h"

Base::Base()
{
	m_A = 100;
}

void Base::func()
{
	cout << "父类里面的func（）函数调用" << endl;
}

void Base::func(int a)
{
	cout << "父类里面的func（int a）函数调用" << endl;
}

