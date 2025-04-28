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
	friend void counts(); //��ģ����Ԫ(û�н���ģ����������β�)��ģ�������Ԫ
	friend void reports(HasFriend<T>& hf);//��ģ����Ԫ(����ģ����������β�)��ģ�������Ԫ��Ҫ��ʾ���廯



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


void reports(HasFriend<int>& hf)//��ʾ���廯1
{
	cout << "HasFriend<int>: " << hf.item << endl;

}


void reports(HasFriend<double>& hf)//��ʾ���廯2
{
	cout << "HasFriend<double>: " << hf.item << endl;

}