#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	string m_Name;
	int m_Age;

	Person();
	Person(string name, int age);
};







#endif 
