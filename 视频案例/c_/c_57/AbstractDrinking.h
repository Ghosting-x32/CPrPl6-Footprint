#ifndef ABSTRACTDRINKING_H_
#define ABSTRACTDRINKING_H_
#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking//抽象类,无法实例化
{
public:
	virtual void Boil() = 0;//纯虚函数实现动态多态
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void makedrink();

};









#endif