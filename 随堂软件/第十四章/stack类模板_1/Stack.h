#pragma once
#include<iostream>
#include<string>

using namespace std;

template <typename Type>
class Stack
{
private:
	enum {MAX = 10};
	Type items[MAX];
	int top;



public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);




};


template <typename Type>
Stack<Type>::Stack()
{
	this->top = 0;

}


template <typename Type>
bool Stack<Type>::isempty()
{
	return this->top == 0;

}


template <typename Type>
bool Stack<Type>::isfull()
{
	return this->top == MAX;

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


