#ifndef COFFEE_H_
#define COFFEE_H_
#include<iostream>
#include<string>
#include"AbstractDrinking.h"
using namespace std;

class Coffee : public AbstractDrinking
{
public:
	void Boil();
	void Brew();
	void PourInCup();
	void PutSomething();
};








#endif