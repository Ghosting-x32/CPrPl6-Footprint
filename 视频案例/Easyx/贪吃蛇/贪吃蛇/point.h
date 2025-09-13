#pragma once
#include<iostream>
#include<easyx.h>

using namespace std;

class Point
{
private:
	int x;
	int y;
	int w;
	int h;
	int colr_xs;
	COLORREF colr;


public:
	Point(int x_ = 0, int y_ = 0, int w_ = 0, int h_ = 0, int colr_xs_ = 1, COLORREF colr_ = RED);
	void set_x(int x_);
	void set_y(int y_);
	void set_w(int w_);
	void set_h(int h_);
	void set_colr();
	//void set_colr(COLORREF colr_);
	void set_colr_xs(int colr_xs_);

	void show_x();
	void show_y();
	void show_w();
	void show_h();

	int retn_x();
	int retn_y();
	int retn_w();
	int retn_h();
	int retn_colr_xs();
	COLORREF retn_colr();
};
