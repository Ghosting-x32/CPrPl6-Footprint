#include"Boss.h"

Boss::Boss(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

string Boss::getDeptName()
{
	return "�ܲ�";
}

string Boss::getGwzz()
{
	return "����˾��������";
}

void Boss::ShowInfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ��: " << this->getGwzz() << endl;
}
