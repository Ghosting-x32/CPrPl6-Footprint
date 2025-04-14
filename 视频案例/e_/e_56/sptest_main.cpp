#include<iostream>
#include<string>
#include<list>
#include"Person.h"


using namespace std;

void test01();
void printPersonList(const list<Person>& li1);
bool ComparePerson(Person& p1, Person& p2);





int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	list<Person>li1;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	li1.push_back(p1);
	li1.push_back(p2);
	li1.push_back(p3);
	li1.push_back(p4);
	li1.push_back(p5);
	li1.push_back(p6);

	cout << "排序前的li1链表内容：" << endl;
	printPersonList(li1);
	cout << "排序后的li1链表内容：" << endl;

	li1.sort(ComparePerson);
	cout << "------------------------------------------------" << endl;
	printPersonList(li1);
}

void printPersonList(const list<Person>& li1)
{
	for (list<Person>::const_iterator it = li1.begin(); it != li1.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t年龄：" << it->m_Age << "\t身高：" << it->m_Score << endl;
	}
	cout << endl;
}

bool ComparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Score > p2.m_Score;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}	 
}