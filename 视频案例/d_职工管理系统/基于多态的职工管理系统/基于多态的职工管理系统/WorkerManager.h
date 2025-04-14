#ifndef WORKERMANAGER_H_
#define WORKERMANAGER_H_

#include<iostream>
#include<string>
#include<fstream>

#include"Worker.h"
#include"Boss.h"
#include"Employee.h"
#include"Manager.h"

#define FILENAME "empFile.txt"//����һ���곣�������ļ���ַ

using namespace std;

class WorkerManager
{
public:
	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;//�ж��ļ�����������Ƿ�Ϊ��

	WorkerManager();
	~WorkerManager();
	void ShowMenu();
	void ExitSystem();
	void Add_Emp();
	void Save();//��ְ����Ϣд���ļ�
	int get_EmpNum();//��ȡ�ļ���ְ��������
	void init_Emp();//�ļ��������ݲ�Ϊ��ʱ����ʼ��m_EmpArray
	void Show_Emp();
	int IsExist(int id);//�ж�ְ���Ƿ���ڣ����ڷ�����������λ�ã������ڷ���-1
	void Del_Emp();
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
};








#endif 

