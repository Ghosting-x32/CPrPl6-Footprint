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
	ofstream ofs1;
	ofs1.open("sptest.txt", ios::out | ios::binary);//1.二进制写文件的必要条件提供ios::binary
	Person p1 = { "张三", 39 };
	//2.二进制写文件的必要条件提供write（）函数
	ofs1.write((const char*)&p1, sizeof(p1));//第一个形参从Person类地址强行转为const char*
	char buffer1[] = "zhang三 李四 69 王五98";
	ofs1.write((const char*)buffer1, sizeof(buffer1));
	ofs1.close();
}


