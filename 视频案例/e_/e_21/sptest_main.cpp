#include<iostream>
#include<string>
#include<vector>
#include"Person.h"

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
	vector<Person>v1;
	Person p1("张三", 32);
	Person p2("李四", 56);
	Person p3("王五", 23);
	Person p4("赵六", 98);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	for (vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		//cout << "姓名：" << (*it).m_Name << "\t";
		//cout << "年龄：" << (*it).m_Age << endl;
		
		cout << "姓名：" << it->m_Name << "\t";
		cout << "年龄：" << it->m_Age << endl;
	}

	cout << "-----------------------------------------------------" << endl;


	vector<Person*>v2;//数组v2里面存放指针---指向Person的指针
	Person pp1("张三", 32);
	Person pp2("李四", 56);
	Person pp3("王五", 23);
	Person pp4("赵六", 98);

	v2.push_back(&pp1);
	v2.push_back(&pp2);
	v2.push_back(&pp3);
	v2.push_back(&pp4);

	for (vector<Person*>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name << "\t";
		cout << "年龄：" << (*it)->m_Age << endl;
	}










}

