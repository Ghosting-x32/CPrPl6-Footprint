#pragma once
#include<iostream>
#include<string>

using namespace std;

template<typename T>
class TooBig
{
public:
	TooBig(const T& t);
	bool operator()(const T& v);



private:
	T cutoff;



};


template<typename T>
TooBig<T>::TooBig(const T& t)
	:cutoff(t)
{
	

}


template<typename T>
bool TooBig<T>::operator()(const T& v)
{
	return v > this->cutoff;

}