#ifndef ABSTRACTANIMAL_H_
#define ABSTRACTANIMAL_H_
#include<iostream>
#include<string>
using namespace std;

class AbstractAnimal
{
public:
	AbstractAnimal();
	//virtual ~AbstractAnimal();//虚析构函数，实现父类指针释放子类对象（执行了子类中的析构函数）
	virtual ~AbstractAnimal() = 0;//纯虚析构函数，实现父类指针释放子类对象（执行了子类中的析构函数）
	//必须提供纯虚析构函数的实现
	virtual void speak() = 0;
};









#endif