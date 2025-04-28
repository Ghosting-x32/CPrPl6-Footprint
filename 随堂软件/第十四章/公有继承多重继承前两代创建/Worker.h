#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
private:
	string fullname;
	long id;



public:
	Worker(const string& s, long n);
	Worker();
	virtual ~Worker() = 0;
	virtual void Set();
	virtual void Show()const;




};