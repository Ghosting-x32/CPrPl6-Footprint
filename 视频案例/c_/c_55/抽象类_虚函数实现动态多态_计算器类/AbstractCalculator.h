#ifndef ABSTRACTCALCULATOR_H_
#define ABSTRACTCALCULATOR_H_
#include<iostream>
#include<string>
using namespace std;

class AbstractCalculator//������
{
public:
	virtual int getResult();//�麯��ʵ�ֶ�̬��̬
	
	int m_Num1;
	int m_Num2;

};









#endif