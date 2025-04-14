#include<iostream>
#include<string>
#include<set>
#include"IntelCPU.h"
#include"Person.h"



using namespace std;

void test01();
void printPersonSet(const set<Person, IntelCPU>& se1);





int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	set<Person, IntelCPU>se1;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	se1.insert(p1);
	se1.insert(p2);
	se1.insert(p3);
	se1.insert(p4);
	se1.insert(p5);
	se1.insert(p6);

	printPersonSet(se1);

}

void printPersonSet(const set<Person, IntelCPU>& se1)
{
	for (set<Person, IntelCPU>::const_iterator it = se1.begin(); it != se1.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t年龄：" << it->m_Age << "\t身高：" << it->m_Score << endl;
	}
}

