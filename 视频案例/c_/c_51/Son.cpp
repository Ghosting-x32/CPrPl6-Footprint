#ifndef SON_H_
#define SON_H_
#include<iostream>
#include<string>
#include"Base.h"
#include"Base1.h"
using namespace std;

class Son : public Base, public Base1//���ؼ̳У�һ��������Լ̳ж�����࣬��һ�㲻�ᳫʹ��
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
