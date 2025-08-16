#include"point.h"

Point::Point(int x_, int y_)
	:x(x_),y(y_)
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