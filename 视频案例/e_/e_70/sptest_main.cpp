#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<map>

#include"Person.h"

#define CHEHUA 0
#define MEISHU 1
#define YANFA 2



using namespace std;

void test01();
void createPerson(vector<Person>& vPerson);
void printPerve(const vector<Person>& vPerson);
void setGroup(vector<Person>& vPerson, multimap<int, Person>& mPerson);
void showPersonByGroup(const multimap<int, Person>& mPerson);



int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	srand((unsigned int)time(NULL));
	vector<Person>vPerson;
	vPerson.resize(10);

	createPerson(vPerson);
	printPerve(vPerson);

	multimap<int, Person>mPerson;
	setGroup(vPerson, mPerson);

	showPersonByGroup(mPerson);

}

void createPerson(vector<Person>& vPerson)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		vPerson[i].m_Name = "员工";
		vPerson[i].m_Name += nameSeed[i];

		int num = rand() % 10001 + 10000;
		vPerson[i].m_Salary = num;
	}
}

void setGroup(vector<Person>& vPerson, multimap<int, Person>& mPerson)
{
	for (vector<Person>::iterator it = vPerson.begin(); it != vPerson.end(); it++)
	{
		int num = rand() % 3;
		mPerson.insert(pair<int, Person>(num, *it));
	}
}

void printPerve(const vector<Person>& vPerson)
{
	for (vector<Person>::const_iterator it = vPerson.begin(); it != vPerson.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t工资：" << it->m_Salary << endl;
	}
	cout << endl;
}

void showPersonByGroup(const multimap<int, Person>& mPerson)
{
	cout << "策划部门：" << endl;
	int index = 0;
	int count = mPerson.count(CHEHUA);
	for (multimap<int, Person>::const_iterator pos = mPerson.find(CHEHUA); pos != mPerson.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t工资：" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;

	cout << "美术部门：" << endl;
	index = 0;
	count = mPerson.count(MEISHU);
	for (multimap<int, Person>::const_iterator pos = mPerson.find(MEISHU); pos != mPerson.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t工资：" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;

	cout << "研发部门：" << endl;
	index = 0;
	count = mPerson.count(YANFA);
	for (multimap<int, Person>::const_iterator pos = mPerson.find(YANFA); pos != mPerson.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t工资：" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
}