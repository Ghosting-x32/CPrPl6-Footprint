#pragma once
#include<iostream>
#include<string>
#include<valarray>

#include"Pair.h"

using namespace std;







class Wine
{
private:
	//valarray�ĵ��ĸ����캯��:
	// const int yr[5]; 
	//valarray<int>v4(yr, 4);
	//v4����ֻ����yr��ǰ4��Ԫ�أ���������v4���鹹����4��yr���飩---���ǹ����˶�ά����
	typedef valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt>PairArray;

	string m_Name;
	int m_YrNum;
	PairArray m_YrBot;
	


public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);


	void GetBottles();
	void Show();

	string& Label();
	int sum();
};


