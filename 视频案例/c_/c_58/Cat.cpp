#include"Cat.h"

Cat::Cat()
{
	cout << "������Ĭ�Ϲ��캯������!" << endl;
}

Cat::Cat(string name)
{
	cout << "�����й��캯������!" << endl;
	m_Name = new string(name);
}

Cat::~Cat()
{
	cout << "�����������������ã�" << endl;
	if (m_Name != NULL)
	{
		delete m_Name;
		m_Name = NULL;
	}
}

void Cat::speak()
{
	cout << "Сè��˵����" << endl;
}