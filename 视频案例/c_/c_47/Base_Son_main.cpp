#include<iostream>
#include<string>
#include"Base.h"
#include"Son.h"
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
	cout << "size of Son = " << sizeof(Son) << endl;
}

