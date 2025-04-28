#pragma once
#include<iostream>
#include<string>

using namespace std;

//ģ����Ԫ��������ǰ��------1.����һ
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
	//------2.�����
	friend void counts<TT>(); //ģ����Ԫ(û�н���ģ����������β�)��ģ�������Ԫ---��Ҫ��֪��ģ����Ԫ����--<TT>
	friend void reports<>(HasFriendT<TT>& hf);//ģ����Ԫ(����ģ����������β�)��ģ�������Ԫ��Ҫ��ʾ���廯---��Ҫ��֪��ģ����Ԫ����--<>����<HasFriend<TT>>



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


//3.������
template<typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";//�������ڵ�TҪ��ģ��ͷ������Tһ��
	cout << "template count: " << HasFriendT<T>::ct << endl;
}


template<typename T>
void reports(T& hf)
{
	cout << hf.item << endl;

}

