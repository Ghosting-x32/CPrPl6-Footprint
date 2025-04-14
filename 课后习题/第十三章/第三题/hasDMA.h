#pragma once
#include<iostream>
#include<string>

#include"abcDMA.h"

using namespace std;

class hasDMA : public abcDMA
{
private:
	char* style;

public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const hasDMA& hs);
	hasDMA(const char* s, const abcDMA& rs);
	virtual ~hasDMA();

	hasDMA& operator=(const hasDMA& rs);
	virtual void View();



	
};







