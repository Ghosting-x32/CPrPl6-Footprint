#include "sptest.h"

void Student::setName(string name)
{
	m_Name = name;
}

void Student::setId(int id)
{
	m_Id = id;
}

void Student::showStudent()
{
	cout << "������ " << m_Name << "\t" << "ѧ�ţ� " << m_Id << endl;
}