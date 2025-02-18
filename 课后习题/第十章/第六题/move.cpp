#include<iostream>
#include"move.h"

Move::Move()
{
	x = 0.0;
	y = 0.0;
}

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

Move::~Move()
{
}

void Move::showmove()const
{
	std::cout << "x = " << x << " !" << std::endl;
	std::cout << "y = " << y << " !" << std::endl;
}

Move Move::add(const Move& m)const
{
	double linx;
	double liny;
	linx = m.x + this->x;
	liny = m.y + this->y;
	Move linle = Move(linx, liny);
	return linle;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}