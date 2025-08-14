#pragma once
#include<iostream>

using namespace std;

class Example
{
private:
	int feet;
	int inches;


public:
	Example();
	Example(int ft);
	~Example();
	void show_in()const;
	void show_ft()const;
	void use_ptr()const;



};
