#pragma once
#include<iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;



public:
	Point(int x_, int y_);
	void set_x(int x_);
	void set_y(int y_);
	void show_x();
	void show_y();
	int retn_x();
	int retn_y();
};
