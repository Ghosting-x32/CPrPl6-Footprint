#ifndef MANAGER_H_
#define MANAGER_H_
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

#include"Identity.h"
#include"GlobalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"

using namespace std;

class Manager : public Identity
{
public:
	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;



	Manager();//默认构造函数
	Manager(string name, string pwd);//有参构造函数---姓名、密码
	void operMenu();//菜单界面
	void addPerson();//添加账号
	void showPerson();//查看账号
	void showComputer();//查看机房信息
	void cleanFile();//清空预约记录
	void initVector();//从文件中读取学生和老师信息储存到容器中----初始化两个容器
	bool checkRepeat(int id, int type);//检测学号/职工编号是否重复---学号/职工编号、身份
	void initvCom();//从文件中读取计算机机房信息储存到容器中----初始化容器
};






#endif 
