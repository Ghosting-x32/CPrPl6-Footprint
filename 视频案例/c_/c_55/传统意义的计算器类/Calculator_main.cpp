#include<iostream>
#include<string>
#include"Calculator.h"

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
	Calculator abc;
	abc.m_Num1 = 10;
	abc.m_Num2 = 10;
	cout << abc.m_Num1 << " + " << abc.m_Num2 << " = " << abc.getResult("+") << endl;
	cout << abc.m_Num1 << " - " << abc.m_Num2 << " = " << abc.getResult("-") << endl;
	cout << abc.m_Num1 << " * " << abc.m_Num2 << " = " << abc.getResult("*") << endl;
}

