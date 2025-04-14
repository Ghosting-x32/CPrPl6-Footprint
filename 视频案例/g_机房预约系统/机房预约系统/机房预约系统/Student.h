#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<string>
#include<vector>
#include<fstream>


#include"Identity.h"
#include"GlobalFile.h"
#include"ComputerRoom.h"
#include"OrderFile.h"

using namespace std;

class Student : public Identity
{
public:
	int m_Id;//学生学号
	vector<ComputerRoom>vCom;


	Student();//默认构造函数
	Student(int id, string name, string pwd);//有参构造函数----学号、姓名、密码
	void operMenu();//菜单界面
	void applyOrder();//申请预约
	void showMyOrder();//查看我的预约
	void showAllOrder();//查看所有预约
	void cancelOrder();//取消预约
	void initvCom();//从文件中读取计算机机房信息储存到容器中----初始化容器

};




#endif 
