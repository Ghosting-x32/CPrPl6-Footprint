#ifndef CIRCLE_H_
#define CIRCLE_H_
#include<iostream>
#include<string>
#include"point.h"
using namespace std;

class Circle//����һ��Բ��
{
private:
	int m_R;//Բ�İ뾶
	Point m_Center;//Բ��Բ�ģ��õ���ʵ�֣���ĳ�Ա��������һ������廯�Ķ���

public:
	void setR(int r);//���Բ�ذ뾶
	int getR();//��ȡԲ�İ뾶
	void setCenter(Point& center);//���Բ��Բ��
	Point getCenter();//��ȡԲ��Բ��

};








#endif