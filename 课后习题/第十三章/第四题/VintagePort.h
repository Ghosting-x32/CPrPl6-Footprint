#pragma once
#include<iostream>
#include<string>
#include<cstring>

#include"Port.h"

using namespace std;

class VintagePort : public Port
{
private:
	char* nickname;
	int year;


public:
	VintagePort(const char* ni = "none", int y = 0, const char* br = "none", const char* st = "none", int b = 0);
	VintagePort(const VintagePort& vi);
	virtual ~VintagePort();
	VintagePort& operator=(const VintagePort& vi);
	virtual void Show()const;
	friend ostream& operator<<(ostream& os, const VintagePort& p);

};