#pragma once
#include<iostream>
#include<string>

#include"Grand.h"
#include"Superb.h"


using namespace std;

class Magnificent : public Superb
{
private:
	char ch;

public:
	Magnificent(int h = 0, char c = 'A');
	virtual void Speak()const;
	virtual int Value()const;
	virtual void Say()const;


};