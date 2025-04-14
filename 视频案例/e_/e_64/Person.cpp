#include "Person.h"

Person::Person()
{

}

Person::Person(string name,int age, int score)
{
	this->m_Name = name;
	this->m_Age = age;
	this->m_Score = score;
}