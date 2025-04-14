#include"Boss.h"

Boss::Boss(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

string Boss::getDeptName()
{
	return "总裁";
}

string Boss::getGwzz()
{
	return "管理公司所有事务";
}

void Boss::ShowInfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t岗位职责: " << this->getGwzz() << endl;
}
