#ifndef ORDERFILE_H_
#define ORDERFILE_H_
#include<iostream>
#include<string>
#include<map>
#include<fstream>

#include"GlobalFile.h"

using namespace std;

class OrderFile//ԤԼ��
{
public:
	int m_Size;//ԤԼ��Ϣ����

	//  key ԤԼ��Ϣ������ value �����¼��ֵ��
	map<int, map<string, string>>m_orderData;//�����ļ��ж�ȡ��ԤԼ��Ϣ



	OrderFile();//���캯��
	void updateOrder();//����ԤԼ��¼


};















#endif 

