#include"Employee.h"

Employee::Employee(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

string Employee::getDeptName()
{
	return "员工";
}

string Employee::getGwzz()
{
	return "完成经理交给的任务";
}

void Employee::ShowInfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t岗位职责: " << this->getGwzz() << endl;
}
