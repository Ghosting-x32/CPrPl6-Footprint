#pragma once
#include<iostream>
#include<string>

using namespace std;

template <typename T1, typename T2>
class Pair
{
private:
	T1 a;
	T2 b;


public:
	Pair();
	Pair(const T1& aval, const T2& bval);
	T1& first();
	T2& second();
	T1 first()const;
	T2 second()const;





};


template <typename T1, typename T2>
Pair<T1, T2>::Pair()
{


}



template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& aval, const T2& bval)
{
	this->a = aval;
	this->b = bval;

}


template <typename T1, typename T2>
T1& Pair<T1, T2>::first()
{
	return this->a;

}


template <typename T1, typename T2>
T2& Pair<T1, T2>::second()
{

	return this->b;
}


template <typename T1, typename T2>
T1 Pair<T1, T2>::first()const
{
	return this->a;

}


template <typename T1, typename T2>
T2 Pair<T1, T2>::second()const
{
	return this->b;

}