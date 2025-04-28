#pragma once
#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class bad_gmean : public logic_error//第二题测试代码
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0, const string& s = "Index error in bad_gmean object\n");
	const char* mesg();



};
