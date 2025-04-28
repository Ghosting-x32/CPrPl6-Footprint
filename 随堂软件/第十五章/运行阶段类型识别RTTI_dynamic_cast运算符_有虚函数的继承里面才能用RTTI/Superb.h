#pragma once
#include<iostream>
#include<string>

#include"Grand.h"

using namespace std;

class Superb : public Grand
{
public:

	Superb(int h = 0);
	virtual void Speak()const;
	virtual int Value()const;
	virtual void Say()const;


};