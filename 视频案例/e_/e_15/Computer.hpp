//模板类与友元的两种用法
#ifndef COMPUTER_H_
#define COMPUTER_H_
#include<iostream>
#include<string>

using namespace std;

//1.全局函数配合友元类外实现,要先告诉编译器有这个模板类，还要告诉编译器有这个模板函数
template<typename NameType, typename AgeType>
class Computer;
template<typename NameType, typename AgeType>
void ShowComputer(Computer<NameType, AgeType>& p);
//1.全局函数配合友元类外实现,要先告诉编译器有这个模板类，还要告诉编译器有这个模板函数

template<typename NameType, typename AgeType>
class Computer
{	
	friend void ShowComputer<>(Computer<NameType, AgeType>& p);//1.全局函数配合友元类外实现,要先告诉编译器有这个模板类，还要告诉编译器有这个模板函数
	friend void ShowComputer1(Computer<NameType, AgeType>& p)//2.全局函数类内实现
	{
		cout << "姓名： " << p.m_Name << endl;
		cout << "年龄： " << p.m_Age << endl;
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
	cout << "姓名： " << p.m_Name << endl;
	cout << "年龄： " << p.m_Age << endl;
}