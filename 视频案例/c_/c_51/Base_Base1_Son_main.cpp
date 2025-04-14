#include<iostream>
#include<string>
#include"Base.h"
#include"Base1.h"
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
	Son s1;
	cout << "Base m_A = " << s1.m_A << endl;
	cout << "Base1 m_B = " << s1.m_B << endl;
	cout << "Son  m_C = " << s1.m_C << endl;
	cout << "Son m_D = " << s1.m_D << endl;
}

