#ifndef WORKER_H_
#define WORKER_H_

#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	virtual void ShowInfo() = 0;
	virtual string getDeptName() = 0;//员工岗位名字获取
	virtual string getGwzz() = 0;//员工岗位职责获取


	int m_Id;
	string m_Name;
	int m_DeptId;
};





#endif 

