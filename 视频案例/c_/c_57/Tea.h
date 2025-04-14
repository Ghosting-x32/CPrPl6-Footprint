#ifndef TEA_H_
#define TEA_H_
#include<iostream>
#include<string>
#include"AbstractDrinking.h"

using namespace std;


class Tea : public AbstractDrinking
{
public:
	void Boil();
	void Brew();
	void PourInCup();
	void PutSomething();


};







#endif