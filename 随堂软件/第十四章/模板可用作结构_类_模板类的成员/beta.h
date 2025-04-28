#pragma once
#include<iostream>
#include<string>

using namespace std;

template <typename T>
class beta
{
private:
	template<typename V>
	class hold;
	hold<T>q;
	hold<int>n;

public:
	beta(T t, int i);
	template<typename U>
	U blab(U u, T t);
	void Show()const;




};


template <typename T>
template<typename V>
class beta<T>::hold
{
private:
	V val;


public:
	hold(V v = 0);
	void show() const;
	V Value()const;


};


template <typename T>
template<typename V>
beta<T>::hold<V>::hold(V v)
{
	this->val = v;

}



template <typename T>
template<typename V>
void beta<T>::hold<V>::show() const
{
	cout << this->val << endl;

}


template <typename T>
template<typename V>
V beta<T>::hold<V>::Value()const
{

	return this->val;
}


//==========================================================

template <typename T>
beta<T>::beta(T t, int i)
{
	this->q = t;
	this->n = i;

}


template <typename T>
template<typename U>
U beta<T>::blab(U u, T t)
{
	return (n.Value() + q.Value()) * u / t;

}


template <typename T>
void beta<T>::Show()const
{
	this->q.show();
	this->n.show();

}