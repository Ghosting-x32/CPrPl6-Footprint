#pragma once
#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class bad_hmean : public logic_error//�ڶ�����Դ���
{
private:
	double v1;
	double v2;



public:
	bad_hmean(double a = 0, double b = 0, const string& s = "Index error in bad_hmean object\n");
	void mesg();



};
