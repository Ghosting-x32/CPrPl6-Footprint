#pragma once
#include<iostream>

using namespace std;

class Useless
{
private:

	int n;
	char* pc;
	static int ct;
	void ShowObject()const;



public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless& f);
	Useless(Useless&& f);
	~Useless();
	Useless operator+(const Useless& f)const;
	void ShowData()const;






};