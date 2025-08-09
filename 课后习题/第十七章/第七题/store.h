#pragma once
#include<iostream>
#include<string>


using namespace std;


class Store
{
private:
	ostream & os;



public:


	Store(ostream & o);

	void operator()(const string& str1);









};
