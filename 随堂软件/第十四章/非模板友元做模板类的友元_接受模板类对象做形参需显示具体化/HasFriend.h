#pragma once
#include<iostream>
#include<string>

using namespace std;


template<typename T>
class HasFriend
{
private:
	T item;
	static int ct;



public:
	HasFriend(const T& i);
	~HasFriend();
	friend void counts(); //非模板友元(没有接受模板类对象做形参)做模板类的友元
	friend void reports(HasFriend<T>& hf);//非模板友元(接受模板类对象做形参)做模板类的友元需要显示具体化



};


template<typename T>
int HasFriend<T>::ct = 0;

template<typename T>
HasFriend<T>::HasFriend(const T& i)
{
	this->item = i;
	this->ct++;

}


template<typename T>
HasFriend<T>::~HasFriend()
{

	this->ct--;
}


void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}


void reports(HasFriend<int>& hf)//显示具体化1
{
	cout << "HasFriend<int>: " << hf.item << endl;

}


void reports(HasFriend<double>& hf)//显示具体化2
{
	cout << "HasFriend<double>: " << hf.item << endl;

}