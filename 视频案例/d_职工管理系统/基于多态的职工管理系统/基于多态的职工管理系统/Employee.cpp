#include"Employee.h"

Employee::Employee(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

string Employee::getDeptName()
{
	return "Ա��";
}

string Employee::getGwzz()
{
	return "��ɾ�����������";
}

void Employee::ShowInfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ��: " << this->getGwzz() << endl;
}
