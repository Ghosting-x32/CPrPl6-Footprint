#ifndef SPTEST_H_
#define SPTEST_H_
#include<iostream>
#include<string>
using namespace std;



class Cube
{
private:
	int m_L;//立方体的长
	int m_W;//立方体的宽
	int m_H;//立方体的高
	
public:
	void setL(int l);//设置长
	int getL();//获取长
	void setW(int w);//设置宽
	int getW();//获取宽
	void setH(int h);//设置高
	int getH();//获取高
	int calculateS();//计算面积
	int calculateV();//计算体积
	bool isSameByClass(Cube& c);//成员函数比较两个立方体是否相等
};






#endif