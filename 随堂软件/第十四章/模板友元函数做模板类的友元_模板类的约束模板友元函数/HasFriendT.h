#pragma once
#include<iostream>
#include<string>

using namespace std;

//模板友元函数声明前置------1.步骤一
template<typename T>
void counts();

template<typename T>
void reports(T& hf);




template<typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;



public:
	HasFriendT(const TT& i);
	~HasFriendT();
	//------2.步骤二
	friend void counts<TT>(); //模板友元(没有接受模板类对象做形参)做模板类的友元---需要告知是模板友元函数--<TT>
	friend void reports<>(HasFriendT<TT>& hf);//模板友元(接受模板类对象做形参)做模板类的友元需要显示具体化---需要告知是模板友元函数--<>或者<HasFriend<TT>>



};


template<typename TT>
int HasFriendT<TT>::ct = 0;

template<typename TT>
HasFriendT<TT>::HasFriendT(const TT& i)
{
	this->item = i;
	this->ct++;

}


template<typename TT>
HasFriendT<TT>::~HasFriendT()
{

	this->ct--;
}


//3.步骤三
template<typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";//函数体内的T要与模板头给出的T一致
	cout << "template count: " << HasFriendT<T>::ct << endl;
}


template<typename T>
void reports(T& hf)
{
	cout << hf.item << endl;

}

