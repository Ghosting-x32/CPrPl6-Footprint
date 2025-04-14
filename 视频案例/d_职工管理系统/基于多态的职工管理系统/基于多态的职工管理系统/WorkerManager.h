#ifndef WORKERMANAGER_H_
#define WORKERMANAGER_H_

#include<iostream>
#include<string>
#include<fstream>

#include"Worker.h"
#include"Boss.h"
#include"Employee.h"
#include"Manager.h"

#define FILENAME "empFile.txt"//创建一个宏常量储存文件地址

using namespace std;

class WorkerManager
{
public:
	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;//判断文件里面的数据是否为空

	WorkerManager();
	~WorkerManager();
	void ShowMenu();
	void ExitSystem();
	void Add_Emp();
	void Save();//把职工信息写进文件
	int get_EmpNum();//获取文件中职工的人数
	void init_Emp();//文件里面数据不为空时，初始化m_EmpArray
	void Show_Emp();
	int IsExist(int id);//判断职工是否存在，存在返回所在数组位置，不存在返回-1
	void Del_Emp();
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
};








#endif 

