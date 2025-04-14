#include<iostream>
#include<string>
#include"AbstractAnimal.h"
#include"Cat.h"

using namespace std;
void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	AbstractAnimal* abc = new Cat("Tom");
	abc->speak();
	delete abc;
}


