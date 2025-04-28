#pragma once
#include<iostream>
#include<string>
#include<stdexcept>

#include"bad_hmean.h"

using namespace std;

class bad_gmean : public bad_hmean//µÚ3Ìâ²âÊÔ´úÂë
{
public:
	
	bad_gmean(double a = 0, double b = 0, const string& s = "Index error in bad_gmean object\n");
	virtual void mesg();



};
