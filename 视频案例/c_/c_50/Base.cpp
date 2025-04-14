#include"Base.h"

int Base::m_A = 100;
void Base::func()
{
	cout << "父类里面的static func（）函数调用" << endl;
}

void Base::func(int a)
{
	cout << "父类里面的static func（int a）函数调用" << endl;
}

