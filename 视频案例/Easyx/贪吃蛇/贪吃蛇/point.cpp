#include"point.h"

Point::Point(int x_, int y_, int w_, int h_, int colr_xs_, COLORREF colr_)
	:x(x_),y(y_),w(w_),h(h_),colr_xs(colr_xs_),colr(colr_)
{



}


void Point::set_x(int x_)
{
	x = x_;


}


void Point::set_y(int y_)
{
	y = y_;

}

void Point::show_x()
{
	cout << x << endl;

}


void Point::show_y()
{

	cout << y << endl;
}


int Point::retn_x()
{
	return x;

}


int Point::retn_y()
{
	return y;

}


void Point::set_w(int w_)
{

	w = w_;

}


void Point::set_h(int h_)
{

	h = h_;

}


void Point::show_w()
{

	cout << w << endl;

}


void Point::show_h()
{

	cout << h << endl;

}



int Point::retn_w()
{

	return w;


}


int Point::retn_h()
{

	return h;

}

void Point::set_colr()
{
	
	colr = HSVtoRGB(colr_xs * 10, 0.9, 1);

}


COLORREF Point::retn_colr()
{

	return colr;

}


void Point::set_colr_xs(int colr_xs_)
{
	colr_xs = colr_xs_;


}

//void Point::set_colr(COLORREF colr_)
//{
//
//	colr = colr_;
//
//}

int Point::retn_colr_xs()
{

	return colr_xs;

}