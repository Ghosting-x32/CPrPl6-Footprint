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
	int m_Id;//ѧ��ѧ��
	vector<ComputerRoom>vCom;


	Student();//Ĭ�Ϲ��캯��
	Student(int id, string name, string pwd);//�вι��캯��----ѧ�š�����������
	void operMenu();//�˵�����
	void applyOrder();//����ԤԼ
	void showMyOrder();//�鿴�ҵ�ԤԼ
	void showAllOrder();//�鿴����ԤԼ
	void cancelOrder();//ȡ��ԤԼ
	void initvCom();//���ļ��ж�ȡ�����������Ϣ���浽������----��ʼ������

};




#endif 
