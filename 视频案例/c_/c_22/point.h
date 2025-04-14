#ifndef POINT_H_
#define POINT_H_
#include<iostream>
#include<string>
using namespace std;

class Point//创建一个点类
{
private:
	int m_X;//点的横坐标
	int m_Y;//点的纵坐标

public:
	void setX(int x);//添加点的横坐标
	int getX();//获取点的横坐标
	void setY(int y);//添加点的纵坐标
	int getY();//获取点的纵坐标

};








#endif