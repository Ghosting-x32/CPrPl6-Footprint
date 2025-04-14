#ifndef INTELCPU_H_
#define INTELCPU_H_
#include<iostream>
#include<string>
#include"Person.h"

using namespace std;

class IntelCPU
{
public:
	bool operator()(const Person& p1, const Person& p2)const;//仿函数作为容器的比较器时必须要有const修饰
};





#endif