#include<iostream>
#include<string>
#include"Animal.h"
#include"Sheep.h"
#include"Tuo.h"
using namespace std;
void DoSpeak(Animal& animal);
void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}

void test01()
{
	Sheep s1;
	Tuo t1;
	DoSpeak(s1);//动态多态，运行时才知道指针指向s1（Sheep对象）

	DoSpeak(t1);
	
}

void DoSpeak(Animal& animal)
{
	animal.speak();
}