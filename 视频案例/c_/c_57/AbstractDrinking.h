#ifndef ABSTRACTDRINKING_H_
#define ABSTRACTDRINKING_H_
#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking//������,�޷�ʵ����
{
public:
	virtual void Boil() = 0;//���麯��ʵ�ֶ�̬��̬
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void makedrink();

};









#endif