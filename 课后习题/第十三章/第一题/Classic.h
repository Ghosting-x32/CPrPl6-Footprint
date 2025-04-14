#pragma once
#include<iostream>
#include<string>
#include<cstring>

#include"Cd.h"


using namespace std;

class Classic : public Cd
{
private:
	char Main_works[50];

public:
	Classic(const char* m = "m", const char* s1 = "s1", const char* s2 = "s2", int n = 0, double x = 0.0);
	virtual void Report()const;


};







