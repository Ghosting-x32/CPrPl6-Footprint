#ifndef COMPUTER_H_
#define COMPUTER_H_
#include<iostream>
#include<string>

using namespace std;

template<typename NameType, typename AgeType>
class Computer
{
public:
	NameType m_Name;
	AgeType m_Age;

	Computer(NameType name, AgeType age);//��ģ���Ա����������ʵ�ֱ���д��һ�𣬲��ܷ��ļ�д---����취(�ļ���Ҫ��Ϊ.hpp)
	void ShowComputer();


};



#endif



template<typename NameType, typename AgeType>
Computer<NameType, AgeType>::Computer(NameType name, AgeType age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<typename NameType, typename AgeType>
void Computer<NameType, AgeType>::ShowComputer()
{
	cout << "������ " << this->m_Name << endl;
	cout << "���䣺 " << this->m_Age << endl;
}