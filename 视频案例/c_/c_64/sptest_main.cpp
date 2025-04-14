#include<iostream>
#include<string>
#include<fstream>
#include "Person.h"



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
	ifstream ifs1;
	ifs1.open("sptest.txt", ios::out | ios::binary);//1.二进制读文件的必要条件提供ios::binary
	if (!ifs1.is_open())
	{
		cout << "文件打开失败！" << endl;
	}
	Person p1;
	//2.二进制读文件的必要条件提供read()函数
	ifs1.read((char*)&p1, sizeof(Person));//第一个形参从Person类地址强行转为char*
	cout << "姓名：" << p1.m_Name << endl;
	cout << "年龄：" << p1.m_Age << endl;
	ifs1.close();
}


