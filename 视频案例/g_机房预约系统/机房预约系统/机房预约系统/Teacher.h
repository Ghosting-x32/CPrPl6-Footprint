#ifndef TEACHER_H_
#define TEACHER_H_
#include<iostream>
#include<string>
#include<vector>

#include"Identity.h"
#include"GlobalFile.h"
#include"OrderFile.h"

using namespace std;

class Teacher : public Identity
{
public:
	int m_EmpId;


	Teacher();//默认构造函数
	Teacher(int empid, string name, string pwd);//有参构造函数---职工编号、姓名、密码
	void operMenu();//菜单界面
	void showAllOrder();//查看所有预约
	void validOrder();//审核预约


};





#endif 

