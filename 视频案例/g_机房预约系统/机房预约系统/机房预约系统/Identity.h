#ifndef IDENTITY_H_
#define IDENTITY_H_
#include<iostream>
#include<string>

using namespace std;

class Identity
{
public:
	virtual void operMenu() = 0;//��ݳ������

	string m_Name;
	string m_Pwd;
};


#endif 

