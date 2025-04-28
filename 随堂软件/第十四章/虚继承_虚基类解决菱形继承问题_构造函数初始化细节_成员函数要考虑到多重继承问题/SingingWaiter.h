#pragma once
#include<iostream>
#include<string>

#include"Worker.h"
#include"Singer.h"
#include"Waiter.h"

using namespace std;

class SingingWaiter : public Singer, public Waiter
{
protected:
	virtual void Data()const;
	virtual void Get();

public:
	SingingWaiter();
	SingingWaiter(const string& s, long n, int p = 0, int v = other);
	SingingWaiter(const Worker& wk, int p = 0, int v = other);
	SingingWaiter(const Singer& wt, int p = 0);
	SingingWaiter(const Waiter& wt, int v = other);

	virtual void Set();
	virtual void Show()const;



};