#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void r1(const double& rx) { cout << rx << endl; }
void r2(double& rx) { cout << rx << endl; }
void r3(double&& rx) { cout << rx << endl; }


int main()
{
	double w = 10.0;
	r1(w);
	r1(w + 1);
	r1(up(w));
	r2(w);
	r2(w + 1);
	r2(up(w));
	r3(w);
	r3(w + 1);
	r3(up(w));
	return 0;
}


/*
r1(w)�Ϸ����β�rx ָ��w��
r1(w+1)�Ϸ����β�rx ָ��һ����ʱ�����������������ʼ��Ϊw+1��
r1(up(w))�Ϸ����β�rx ָ��һ����ʱ�����������������ʼ��Ϊup(w)�ķ���ֵ��
һ����ԣ�����ֵ���ݸ�const ��ֵ���ò���ʱ������������ʼ��Ϊ��ֵ������ֵ���ݸ�����ʱ��const
��ֵ���ò�����ָ����ֵ����ʱ������




r2(w)�Ϸ����β�rx ָ��w��
r2(w+1)�Ƿ�����Ϊw+1 ��һ����ֵ��
r2(up(w))�Ƿ�����Ϊup(w)�ķ���ֵ��һ����ֵ��
һ����ԣ�����ֵ���ݸ���const ��ֵ���ò���ʱ������������ʼ��Ϊ��ֵ������const ��ֵ�ββ���
������ֵʵ�Ρ�




r3(w)�Ƿ�����Ϊ��ֵ���ò���ָ����ֵ����w����
r3(w+1)�Ϸ���rx ָ����ʽw+1 ����ʱ������
r3(up(w))�Ϸ���rx ָ��up(w)����ʱ����ֵ��



*/