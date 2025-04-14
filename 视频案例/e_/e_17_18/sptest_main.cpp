#include<iostream>
#include<string>
#include"MyArray.hpp"
#include"IntelCPU.h"



void test01();
void printIntArray(MyArray<int>& p1);
void printIntelCPUArray(MyArray<IntelCPU>& p1);


int main()
{
	test01();


	system("pause");
	return 0;
}


void test01()
{
	MyArray<int>p1(5);
	for (int i = 0; i < 5; i++)
	{
		p1.Push_Back(i);
	}
	printIntArray(p1);
	cout << "数组的容量：" << p1.get_Capacity() << endl;
	cout << "数组的大小：" << p1.get_Size() << endl;
	cout << "---------------------------" << endl;

	MyArray<int>p2(p1);
	printIntArray(p2);
	cout << "数组的容量：" << p2.get_Capacity() << endl;
	cout << "数组的大小：" << p2.get_Size() << endl;
	cout << "---------------------------" << endl;
	cout << "尾删法后的p2数组内容是：" << endl;
	p2.Pob_Back();
	printIntArray(p2);
	cout << "数组的容量：" << p2.get_Capacity() << endl;
	cout << "数组的大小：" << p2.get_Size() << endl;
	cout << "---------------------------" << endl;
	cout << "---------------------------" << endl;

	MyArray<IntelCPU>intelCPU1(5);
	IntelCPU incpu1("张三", 23);
	IntelCPU incpu2("李四", 53);
	IntelCPU incpu3("王五", 20);
	IntelCPU incpu4("赵六", 100);
	IntelCPU incpu5("吴二", 63);
	intelCPU1.Push_Back(incpu1);
	intelCPU1.Push_Back(incpu2);
	intelCPU1.Push_Back(incpu3);
	intelCPU1.Push_Back(incpu4);
	intelCPU1.Push_Back(incpu5);
	printIntelCPUArray(intelCPU1);
	cout << "数组的容量：" <<intelCPU1.get_Capacity() << endl;
	cout << "数组的大小：" << intelCPU1.get_Size() << endl;
	cout << "---------------------------" << endl;
	cout << endl << "尾删法后的intelCPU1数组内容是：" << endl;
	intelCPU1.Pob_Back();
	printIntelCPUArray(intelCPU1);
	cout << "数组的容量：" << intelCPU1.get_Capacity() << endl;
	cout << "数组的大小：" << intelCPU1.get_Size() << endl;
}

void printIntArray(MyArray<int>& p1)
{
	for (int i = 0; i < p1.get_Size(); i++)
	{
		cout << p1[i] << " ";
	}
	cout << endl;
}

void printIntelCPUArray(MyArray<IntelCPU>& p1)
{
	for (int i = 0; i < p1.get_Size(); i++)
	{
		cout << "姓名：" << p1[i].m_Name << "\t" << "年龄：" << p1[i].m_Age << endl;
	}
	cout << endl;
}