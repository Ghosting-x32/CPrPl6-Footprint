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

	Computer(NameType name, AgeType age);//类模板成员函数声明和实现必须写在一起，不能分文件写---解决办法(文件名要改为.hpp)
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
	cout << "姓名： " << this->m_Name << endl;
	cout << "年龄： " << this->m_Age << endl;
}