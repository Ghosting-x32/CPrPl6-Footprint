#pragma once
#include<iostream>
#include<string>

using namespace std;






template<typename T>
class ManyFriend
{
private:
	T item;



public:
	ManyFriend(const T& i);

	template<typename C, typename D>
	friend void show2(C& c, D& d);

};


template<typename T>
ManyFriend<T>::ManyFriend(const T& i)
{

	this->item = i;
}



template<typename C, typename D>
void show2(C& c, D& d)
{
	cout << c.item << ", " << d.item << endl;

}