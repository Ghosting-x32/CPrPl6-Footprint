#pragma once
#include<iostream>
#include<string>

using namespace std;


//还可以这样template <template<typename T>class Thing， typename U, typename V>
template <template<typename T>class Thing>
class Crab
{
private:
	Thing<int>s1;//Thing<U>s1;
	Thing<double>s2;//Thing<V>s2;
	

public:
	Crab();
	bool push(const int& a, const double& x);
	bool pop(int& a, double& x);




};


template <template<typename T>class Thing>
Crab<Thing>::Crab()
{


}


template <template<typename T>class Thing>
bool Crab<Thing>::push(const int& a, const double& x)
{
	return this->s1.push(a) && this->s2.push(x);

}


template <template<typename T>class Thing>
bool Crab<Thing>::pop(int& a, double& x)
{
	return this->s1.pop(a) && this->s2.pop(x);

}