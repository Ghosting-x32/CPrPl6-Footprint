//ģ��������Ԫ�������÷�
#ifndef COMPUTER_H_
#define COMPUTER_H_
#include<iostream>
#include<string>

using namespace std;

//1.ȫ�ֺ��������Ԫ����ʵ��,Ҫ�ȸ��߱����������ģ���࣬��Ҫ���߱����������ģ�庯��
template<typename NameType, typename AgeType>
class Computer;
template<typename NameType, typename AgeType>
void ShowComputer(Computer<NameType, AgeType>& p);
//1.ȫ�ֺ��������Ԫ����ʵ��,Ҫ�ȸ��߱����������ģ���࣬��Ҫ���߱����������ģ�庯��

template<typename NameType, typename AgeType>
class Computer
{	
	friend void ShowComputer<>(Computer<NameType, AgeType>& p);//1.ȫ�ֺ��������Ԫ����ʵ��,Ҫ�ȸ��߱����������ģ���࣬��Ҫ���߱����������ģ�庯��
	friend void ShowComputer1(Computer<NameType, AgeType>& p)//2.ȫ�ֺ�������ʵ��
	{
		cout << "������ " << p.m_Name << endl;
		cout << "���䣺 " << p.m_Age << endl;
	}
private:
	NameType m_Name;
	AgeType m_Age;
public:
	Computer(NameType name, AgeType age);


};



#endif


template<typename NameType, typename AgeType>
Computer<NameType, AgeType>::Computer(NameType name, AgeType age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<typename NameType, typename AgeType>
void ShowComputer(Computer<NameType, AgeType>& p)
{
	cout << "������ " << p.m_Name << endl;
	cout << "���䣺 " << p.m_Age << endl;
}