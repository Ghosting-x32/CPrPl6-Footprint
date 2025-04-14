#ifndef CAT_H_
#define CAT_H_
#include<iostream>
#include<string>
#include"AbstractAnimal.h"
using namespace std;

class Cat : public AbstractAnimal
{
public:
	Cat();
	Cat(string name);
	~Cat();
	void speak();

	string* m_Name;
};








#endif