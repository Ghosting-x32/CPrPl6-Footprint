#ifndef SPTEST_H_
#define SPTEST_H_
#include<iostream>
#include<string>
using namespace std;



class Cube
{
private:
	int m_L;//������ĳ�
	int m_W;//������Ŀ�
	int m_H;//������ĸ�
	
public:
	void setL(int l);//���ó�
	int getL();//��ȡ��
	void setW(int w);//���ÿ�
	int getW();//��ȡ��
	void setH(int h);//���ø�
	int getH();//��ȡ��
	int calculateS();//�������
	int calculateV();//�������
	bool isSameByClass(Cube& c);//��Ա�����Ƚ������������Ƿ����
};






#endif