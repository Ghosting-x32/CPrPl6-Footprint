#include<iostream>
#include<string>
#include"sptest.h"
using namespace std;
//设计一个立方体类
	//1.设置一个立方体的类
	//2.设置立方体类的成员（设计属性）
	//3.设置立方体类的成员函数（计算立方体的体积和面积）（设计行为）
	//4.分别用全局函数和成员函数 对比两个立方体是否相等

bool isSame(Cube& c1, Cube& c2);//成员函数比较两个立方体是否相等

int main()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1立方体的面积是： " << c1.calculateS() << endl;
	cout << "c1立方体的体积是： " << c1.calculateV() << endl;

	Cube c2;
	c2.setL(10);
	c2.setW(13);
	c2.setH(10);
	bool ret;
	ret = isSame(c1, c2);
	if (ret)
	{
		cout << "两个立方体是相等的！" << endl;
	}
	else
	{
		cout << "两个立方体是不相等！" << endl;
	}

	ret = c1.isSameByClass(c2);
	if (ret)
	{
		cout << "成员函数判断 两个立方体是相等的！" << endl;
	}
	else
	{
		cout << "成员函数判断 两个立方体是不相等！" << endl;
	}

	system("pause");
	return 0;
}

bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}