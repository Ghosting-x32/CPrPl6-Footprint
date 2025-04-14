#include<iostream>
#include<string>
#include"AbstractDrinking.h"
#include"Coffee.h"
#include"Tea.h"


using namespace std;
void doWork(AbstractDrinking* abc);
void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}

void doWork(AbstractDrinking* abc)
{
	abc->makedrink();
	delete abc;
}

void test01()
{
	doWork(new Coffee);
	cout << "--------------------" << endl;
	doWork(new Tea);
}


