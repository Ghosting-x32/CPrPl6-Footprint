#include"Base.h"

int Base::m_A = 100;
void Base::func()
{
	cout << "���������static func������������" << endl;
}

void Base::func(int a)
{
	cout << "���������static func��int a����������" << endl;
}

