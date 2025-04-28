#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person
{
private:

	string m_Xing;
	string m_ming;
	



public:

	Person(const string& xi = "none", const string& mi = "none");

	virtual void Show()const;
	virtual void Set();
	virtual ~Person();

};
