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
	int m_Score;

	Person();
	Person(string name, int m_Age, int score);
};







#endif 
