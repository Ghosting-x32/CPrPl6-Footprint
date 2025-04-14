#include"Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

string Manager::getDeptName()
{
	return "经理";
}

string Manager::getGwzz()
{
	return "完成老板交给的任务，并下发任务给员工";
}

void Manager::ShowInfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t岗位职责: " << this->getGwzz() << endl;
}
