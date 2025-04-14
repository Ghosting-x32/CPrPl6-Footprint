#ifndef ANIMAL_H_
#define ANIMAL_H_
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	virtual void speak();//虚函数，函数地址在编译阶段不确定，运行阶段才确定-----由此实现动态多态
	

};









#endif