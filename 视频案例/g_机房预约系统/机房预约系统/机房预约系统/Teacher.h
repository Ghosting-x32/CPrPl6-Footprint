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


	Teacher();//Ĭ�Ϲ��캯��
	Teacher(int empid, string name, string pwd);//�вι��캯��---ְ����š�����������
	void operMenu();//�˵�����
	void showAllOrder();//�鿴����ԤԼ
	void validOrder();//���ԤԼ


};





#endif 

