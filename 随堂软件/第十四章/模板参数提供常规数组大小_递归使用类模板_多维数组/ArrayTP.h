#pragma once
#include<iostream>
#include<string>

using namespace std;

template <typename T, int n>
class ArrayTP
{
private:
	T ar[n];


public:
	ArrayTP();
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
	virtual T operator[](int i)const;//virtual const T& operator[](int i)const;





};


template <typename T, int n>
ArrayTP<T,n>::ArrayTP()
{


}


template <typename T, int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
	{
		this->ar[i] = v;
	}

}


template <typename T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		cerr << "Errir in array limits: " << i << " is out of range\n";
		exit(EXIT_FAILURE);
	}

	return this->ar[i];

}


template <typename T, int n>
T ArrayTP<T, n>::operator[](int i)const
{
	if (i < 0 || i >= n)//检验用户传入的值是否在冲区内
	{//优先使用 std::cerr 输出错误或需要即时显示的消息。
		cerr << "Errir in array limits: " << i << " is out of range\n";//错误信息的输出显示用途cerr，无缓冲
		exit(EXIT_FAILURE);
	}

	return this->ar[i];

}