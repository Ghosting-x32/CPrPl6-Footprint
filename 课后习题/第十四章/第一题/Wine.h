#pragma once
#include<iostream>
#include<string>
#include<valarray>

#include"Pair.h"

using namespace std;







class Wine
{
private:
	//valarray的第四个构造函数:
	// const int yr[5]; 
	//valarray<int>v4(yr, 4);
	//v4数组只拷贝yr的前4个元素（而不是在v4数组构建了4个yr数组）---不是构建了二维数组
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


