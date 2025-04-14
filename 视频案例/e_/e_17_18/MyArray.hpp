#ifndef MYARRAY_H_
#define MYARRAY_H_
#include<iostream>
#include<string>

using namespace std;


template<typename T>
class MyArray
{
private:
	T* m_pAddress;
	int m_Capacity;//数组容量
	int m_Size;//数组大小

public:
	MyArray(int capacity);
	MyArray(const MyArray<T>& arr);
	~MyArray();
	MyArray<T>& operator=(const MyArray<T>& arr);
	void Push_Back(const T& val);
	void Pob_Back();
	T& operator[](int index);
	int get_Capacity();
	int get_Size();


};

template<typename T>
MyArray<T>::MyArray(int capacity)
{
	cout << "有参构造函数调用！" << endl;
	this->m_Size = 0;
	this->m_Capacity = capacity;
	this->m_pAddress = new T[this->m_Capacity];
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& arr)
{
	cout << "复制构造函数调用！" << endl;
	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->m_pAddress = new T[arr.m_Capacity];
	for (int i = 0; i < this->m_Size; i++)
	{
		this->m_pAddress[i] = arr.m_pAddress[i];
	}
}

template<typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& arr)
{
	cout << "operator=函数调用！" << endl;
	if (this->m_pAddress != NULL)
	{
		delete[] this->m_pAddress;
		this->m_pAddress = NULL;
		this->m_Size = 0;
		this->m_Capacity = 0;
	}

	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->m_pAddress = new T[arr.m_Capacity];
	for (int i = 0; i < this->m_Size; i++)
	{
		this->m_pAddress[i] = arr.m_pAddress[i];
	}
	return *this;
}

template<typename T>
MyArray<T>::~MyArray()
{

	if (this->m_pAddress != NULL)
	{
		cout << "析构函数调用！" << endl;
		delete[] m_pAddress;
		this->m_pAddress = NULL;
	}
}

template<typename T>
void MyArray<T>::Push_Back(const T& val)
{
	if (this->m_Size == this->m_Capacity)
	{
		cout << "数组已满，插入失败！" << endl;
		return;
	}
	this->m_pAddress[this->m_Size] = val;
	this->m_Size++;
}

template<typename T>
void MyArray<T>::Pob_Back()
{
	if (this->m_Size == 0)
	{
		cout << "数组为空，删除失败！" << endl;
		return;
	}
	this->m_Size--;//做逻辑上的删除，让用户访问不了数组的最后一个值
}

template<typename T>
T& MyArray<T>::operator[](int index)
{
	return this->m_pAddress[index];
}

template<typename T>
int MyArray<T>::get_Capacity()
{
	return this->m_Capacity;
}

template<typename T>
int MyArray<T>::get_Size()
{
	return this->m_Size;
}

#endif