#pragma once
#include<iostream>
#include<string>

using namespace std;

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0);
	const char* mesg();



};
