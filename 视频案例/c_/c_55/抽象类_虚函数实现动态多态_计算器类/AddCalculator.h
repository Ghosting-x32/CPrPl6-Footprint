#ifndef ADDCALCULATOR_H_
#define ADDCALCULATOR_H_
#include<iostream>
#include<string>
#include"AbstractCalculator.h"
using namespace std;

class AddCalculator : public AbstractCalculator
{
public:
	int getResult();
};








#endif