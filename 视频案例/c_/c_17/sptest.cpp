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
	cout << "ÐÕÃû£º " << m_Name << "\t" << "Ñ§ºÅ£º " << m_Id << endl;
}