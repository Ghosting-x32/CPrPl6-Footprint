#include"Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

string Manager::getDeptName()
{
	return "����";
}

string Manager::getGwzz()
{
	return "����ϰ彻�������񣬲��·������Ա��";
}

void Manager::ShowInfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ��: " << this->getGwzz() << endl;
}
