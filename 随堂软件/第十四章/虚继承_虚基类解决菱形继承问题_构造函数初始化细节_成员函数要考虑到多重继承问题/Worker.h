#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
protected:
	virtual void Data()const;
	virtual void Get();


private:
	string fullname;
	long id;



public:
	Worker(const string& s, long n);
	Worker();
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show()const = 0;




};