#pragma once
#include<iostream>
#include<string>

using namespace std;

class Card
{
private:

	string m_Huase;
	int m_Mianzhi;


public:
	Card(const string& hs, int mz);
	void view()const;
	const string& viewhs()const;
	const int& viewmz()const;


};