#pragma once
#include<iostream>
#include<string>

#include"baseDMA.h"

using namespace std;

class hasDMA : public baseDMA
{
private:
	char* style;

public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const hasDMA& hs);
	hasDMA(const char* s, const baseDMA& rs);
	virtual ~hasDMA();

	hasDMA& operator=(const hasDMA& rs);
	friend ostream& operator<<(ostream& os, const hasDMA& rs);



	
};







