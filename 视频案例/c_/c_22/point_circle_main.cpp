#include<iostream>
#include<string>
#include"point.h"
#include"circle.h"
using namespace std;
void isInCircle(Point& p1, Circle& c1);//判断点p1与圆c1的位置关系


int main()
{
	Point p1;//具体化一个随意点
	p1.setX(10);//给随意点赋值横坐标
	p1.setY(9);//给随意点赋值纵坐标

	Circle c1;//具体化一个任意圆
	c1.setR(10);//给圆赋值半径
	Point center;//使用点类具体化一个点（充当圆心）
	center.setX(10);//给具体化的点（圆心）赋值横坐标
	center.setY(0);//给具体化的点（圆心）赋值纵坐标
	c1.setCenter(center);//将具体化的点赋值给圆心

	isInCircle(p1, c1);



	system("pause");
	return 0;
}

void isInCircle(Point& p1, Circle& c1)
{
	//计算点到圆心的距离的平方
	int distance =
		(p1.getX() - c1.getCenter().getX()) * (p1.getX() - c1.getCenter().getX()) +
		(p1.getY() - c1.getCenter().getY()) * (p1.getY() - c1.getCenter().getY());
	int rDistance = c1.getR() * c1.getR();//计算圆半径的平方
	if (distance == rDistance)
	{
		cout << "点在圆上！" << endl;
	}
	else if (distance < rDistance)
	{
		cout << "点在圆内！" << endl;
	}
	else
	{
		cout << "点在圆外！" << endl;
	}
}
