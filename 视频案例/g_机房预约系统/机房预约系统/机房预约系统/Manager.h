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



	Manager();//Ĭ�Ϲ��캯��
	Manager(string name, string pwd);//�вι��캯��---����������
	void operMenu();//�˵�����
	void addPerson();//����˺�
	void showPerson();//�鿴�˺�
	void showComputer();//�鿴������Ϣ
	void cleanFile();//���ԤԼ��¼
	void initVector();//���ļ��ж�ȡѧ������ʦ��Ϣ���浽������----��ʼ����������
	bool checkRepeat(int id, int type);//���ѧ��/ְ������Ƿ��ظ�---ѧ��/ְ����š����
	void initvCom();//���ļ��ж�ȡ�����������Ϣ���浽������----��ʼ������
};






#endif 
