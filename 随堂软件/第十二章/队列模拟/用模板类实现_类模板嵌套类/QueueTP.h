#pragma once
#include<iostream>
#include<string>

using namespace std;

template<typename Item>
class QueueTP
{
private:
	enum {Q_SIZE = 10};
	class Node
	{
	public:
		Item item;
		Node* next;
		Node(const Item& i): item(i), next(nullptr){}

	};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP<Item>& q);
	QueueTP<Item>& operator=(const QueueTP<Item>& q);



public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);


};


template<typename Item>
QueueTP<Item>::QueueTP(int qs)
	:qsize(qs)
{
	this->front = nullptr;
	this->rear = nullptr;
	this->items = 0;

}


template<typename Item>
QueueTP<Item>::~QueueTP()
{
	Node* temp;
	while (this->front != nullptr)
	{
		temp = this->front;
		this->front = this->front->next;
		delete temp;

	}


}


template<typename Item>
QueueTP<Item>::QueueTP(const QueueTP<Item>& q)
{

	this->qsize = 0;
}



template<typename Item>
QueueTP<Item>& QueueTP<Item>::operator=(const QueueTP<Item>& q)
{
	return *this;

}



template<typename Item>
bool QueueTP<Item>::isempty()const
{

	return this->items == 0;

}


template<typename Item>
bool QueueTP<Item>::isfull()const
{
	return this->items == this->qsize;

}


template<typename Item>
int QueueTP<Item>::queuecount()const
{
	return this->items;

}


template<typename Item>
bool QueueTP<Item>::enqueue(const Item& item)
{
	if (this->isfull())
	{
		return false;
	}

	Node* add = new Node(item);
	this->items++;
	if (this->front == nullptr)
	{
		this->front = add;
	}
	else
	{
		this->rear->next = add;	
	}
	this->rear = add;
	return true;

}


template<typename Item>
bool QueueTP<Item>::dequeue(Item& item)
{
	if (this->isempty())
	{
		return false;
	}

	item = this->front->item;
	this->items--;
	Node* temp = this->front;
	this->front = this->front->next;
	delete temp;
	if (this->items == 0)
	{
		this->rear = nullptr;
	}

	return true;
}