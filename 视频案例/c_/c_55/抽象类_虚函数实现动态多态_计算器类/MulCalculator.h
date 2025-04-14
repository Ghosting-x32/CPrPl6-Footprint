#ifndef MULCALCULATOR_H_
#define MULCALCULATOR_H_
#include<iostream>
#include<string>
#include"AbstractCalculator.h"
using namespace std;

class MulCalculator :  public AbstractCalculator
{
public:
	int getResult();


};





#endif