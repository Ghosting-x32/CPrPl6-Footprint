#ifndef SUBCALCULATOR_H_
#define SUBCALCULATOR_H_
#include<iostream>
#include<string>
#include"AbstractCalculator.h"

using namespace std;


class SubCalculator : public AbstractCalculator
{
public:
	int getResult();


};







#endif