#pragma once
#include<iostream>
#include<string>

#include"Worker.h"

using namespace std;

class Singer : virtual public Worker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone, tenor};
	enum { Vtypes = 7 };

	virtual void Data()const;
	virtual void Get();

private:
	static const char* pv[Vtypes];
	int voice;


public:
	Singer();
	Singer(const string& s, long n, int v = other);
	Singer(const Worker& wk, int v = other);
	virtual void Set();
	virtual void Show()const;




};