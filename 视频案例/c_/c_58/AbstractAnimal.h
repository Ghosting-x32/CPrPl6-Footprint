#ifndef ABSTRACTANIMAL_H_
#define ABSTRACTANIMAL_H_
#include<iostream>
#include<string>
using namespace std;

class AbstractAnimal
{
public:
	AbstractAnimal();
	//virtual ~AbstractAnimal();//������������ʵ�ָ���ָ���ͷ��������ִ���������е�����������
	virtual ~AbstractAnimal() = 0;//��������������ʵ�ָ���ָ���ͷ��������ִ���������е�����������
	//�����ṩ��������������ʵ��
	virtual void speak() = 0;
};









#endif