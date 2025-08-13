#pragma once
#include<iostream>
#include<cmath>

using namespace std;

class f_mod
{
private:

	int dv;


public:
	f_mod(int d);

	bool operator()(int n);


};