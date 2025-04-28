#pragma once
#include<iostream>
#include<string>

#include"Worker.h"

using namespace std;

class Waiter : virtual public Worker
{
protected:
	virtual void Data()const;
	virtual void Get();


private:

	int panache;

public:
	Waiter();
	Waiter(const string& s, long n, int p = 0);
	Waiter(const Worker& wk, int p = 0);
	virtual void Set();
	virtual void Show()const;



};