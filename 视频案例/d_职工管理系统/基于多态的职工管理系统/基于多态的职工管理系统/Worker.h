#ifndef WORKER_H_
#define WORKER_H_

#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	virtual void ShowInfo() = 0;
	virtual string getDeptName() = 0;//Ա����λ���ֻ�ȡ
	virtual string getGwzz() = 0;//Ա����λְ���ȡ


	int m_Id;
	string m_Name;
	int m_DeptId;
};





#endif 

