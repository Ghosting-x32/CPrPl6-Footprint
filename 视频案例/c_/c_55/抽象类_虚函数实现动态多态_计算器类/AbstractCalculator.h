#ifndef ABSTRACTCALCULATOR_H_
#define ABSTRACTCALCULATOR_H_
#include<iostream>
#include<string>
using namespace std;

class AbstractCalculator//抽象类
{
public:
	virtual int getResult();//虚函数实现动态多态
	
	int m_Num1;
	int m_Num2;

};









#endif