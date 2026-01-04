#pragma once
#include<string>
#include<vector>
#include<cctype>
#include<iostream>


using std::string;
using std::vector;
using std::isdigit;
using std::cout;
using std::cin;
using std::endl;


class MyTime
{
public:
	
	
	explicit MyTime(const string& str = "1/1/1990");


	void print();

private:
	unsigned int year_n;
	unsigned int moun_n;
	unsigned int day_n;
	



};

