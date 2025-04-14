#include"Cat.h"

Cat::Cat()
{
	cout << "子类中默认构造函数调用!" << endl;
}

Cat::Cat(string name)
{
	cout << "子类中构造函数调用!" << endl;
	m_Name = new string(name);
}

Cat::~Cat()
{
	cout << "子类中析构函数调用！" << endl;
	if (m_Name != NULL)
	{
		delete m_Name;
		m_Name = NULL;
	}
}

void Cat::speak()
{
	cout << "小猫在说话！" << endl;
}