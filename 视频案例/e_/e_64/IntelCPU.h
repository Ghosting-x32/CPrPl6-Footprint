#ifndef INTELCPU_H_
#define INTELCPU_H_
#include<iostream>
#include<string>
#include"Person.h"

using namespace std;

class IntelCPU
{
public:
	bool operator()(const Person& p1, const Person& p2)const;//�º�����Ϊ�����ıȽ���ʱ����Ҫ��const����
};





#endif