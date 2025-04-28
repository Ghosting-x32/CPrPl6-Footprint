#pragma once
#include<iostream>
#include<string>

using namespace std;

template <typename Type>
class Stack
{
private:
	enum { SIZE = 10 };
	int stacksize;
	Type* items;
	int top;



public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack<Type>& st);
	~Stack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);
	Stack<Type>& operator = (const Stack<Type>& st);




};


template <typename Type>
Stack<Type>::Stack(int ss)
{
	this->stacksize = ss;
	this->top = 0;
	this->items = new Type[this->stacksize];
}


template <typename Type>
Stack<Type>::Stack(const Stack<Type>& st)
{
	this->stacksize = st.stacksize;
	this->top = st.top;
	this->items = new Type[this->stacksize];
	for (int i = 0; i < this->top; i++)
	{
		this->items[i] = st.items[i];
	}

}


template <typename Type>
Stack<Type>::~Stack()
{
	if (this->items != NULL)
	{
		delete[] this->items;
		this->items = NULL;
	}

}


template <typename Type>
bool Stack<Type>::isempty()
{
	return this->top == 0;

}


template <typename Type>
bool Stack<Type>::isfull()
{
	return this->top == this->stacksize;

}


template <typename Type>
bool Stack<Type>::push(const Type& item)
{
	if (this->isfull())
	{
		return false;
	}
	else
	{
		this->items[(this->top)++] = item;
		return true;
	}


}


template <typename Type>
bool Stack<Type>::pop(Type& item)
{
	if (this->isempty())
	{
		return false;
	}
	else
	{
		item = this->items[--(this->top)];
		return true;
	}

}


template <typename Type>
Stack<Type>& Stack<Type>::operator = (const Stack<Type>& st)
{
	if (this == &st)
	{
		return *this;
	}

	if (this->items != NULL)
	{
		delete[] this->items;
		this->items = NULL;
	}

	this->stacksize = st.stacksize;
	this->top = st.top;
	this->items = new Type[this->stacksize];
	for (int i = 0; i < this->top; i++)
	{
		this->items[i] = st.items[i];
	}

	return *this;
}