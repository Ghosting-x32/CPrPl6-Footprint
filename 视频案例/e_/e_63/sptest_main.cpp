#include<iostream>
#include<string>
#include<set>
#include"IntelCPU.h"



using namespace std;

void test01();
void printIntSet(const set<int, IntelCPU>& se1);
void printIntSet2(const set<int>& se2);




int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	cout << "没有自定义排序方法前：" << endl;
	set<int>se2;

	se2.insert(30);
	se2.insert(70);
	se2.insert(20);
	se2.insert(100);
	se2.insert(90);
	printIntSet2(se2);

	cout << "自定义排序方法后：" << endl;
	set<int, IntelCPU>se1;//仿函数作为set容器的比较器

	se1.insert(30);
	se1.insert(70);
	se1.insert(20);
	se1.insert(100);
	se1.insert(90);
	printIntSet(se1);



}

void printIntSet(const set<int, IntelCPU>& se1)
{
	for (set<int, IntelCPU>::const_iterator it = se1.begin(); it != se1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printIntSet2(const set<int>& se2)
{
	for (set<int>::const_iterator it = se2.begin(); it != se2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}