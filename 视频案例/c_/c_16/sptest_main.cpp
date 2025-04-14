#include<iostream>
#include"sptest.h"
using namespace std;



int main()
{
	Circle c1;
	c1.m_r = 10;
	cout << "半径为10的圆其周长是： " << c1.calculateZC() << endl;
	

	system("pause");
	return 0;
}

