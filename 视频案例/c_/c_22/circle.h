#ifndef CIRCLE_H_
#define CIRCLE_H_
#include<iostream>
#include<string>
#include"point.h"
using namespace std;

class Circle//创建一个圆类
{
private:
	int m_R;//圆的半径
	Point m_Center;//圆的圆心，用点类实现（类的成员可以是另一个类具体化的对象）

public:
	void setR(int r);//添加圆地半径
	int getR();//获取圆的半径
	void setCenter(Point& center);//添加圆的圆心
	Point getCenter();//获取圆的圆心

};








#endif