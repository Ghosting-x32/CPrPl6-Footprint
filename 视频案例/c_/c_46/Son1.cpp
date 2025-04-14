#include"Son1.h"

void Son1::func()
{
	m_A = 10;
	m_B = 10;
	//m_C = 10;//保护继承时，子类内不可以访问父类的privat(私有属性）成员
}