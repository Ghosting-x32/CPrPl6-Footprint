#ifndef SON_H_
#define SON_H_
#include<iostream>
#include<string>
#include"Base.h"
#include"Base1.h"
using namespace std;

class Son : public Base, public Base1//多重继承，一个子类可以继承多个父类，但一般不提倡使用
{
public:
	int m_C;
	int m_D;
	Son();
};








#endif

#include"Son.h"

Son::Son()
{
	m_C = 300;
	m_D = 400;
}
