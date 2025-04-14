#ifndef ORDERFILE_H_
#define ORDERFILE_H_
#include<iostream>
#include<string>
#include<map>
#include<fstream>

#include"GlobalFile.h"

using namespace std;

class OrderFile//预约类
{
public:
	int m_Size;//预约信息条数

	//  key 预约信息条数， value 具体记录键值对
	map<int, map<string, string>>m_orderData;//储存文件中读取的预约信息



	OrderFile();//构造函数
	void updateOrder();//更新预约记录


};















#endif 

