#pragma once
#include<iostream>
#include<string>

using namespace std;

class Grand
{
private:

	int hold;


public:
	Grand(int h = 0);
	virtual void Speak()const;
	virtual int Value()const;



};