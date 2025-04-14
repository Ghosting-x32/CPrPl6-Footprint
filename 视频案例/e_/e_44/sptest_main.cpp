#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include"Person.h"


using namespace std;

void test01();
void createPerson(vector<Person>& ve1);
void printPersonVector(const vector<Person>& ve1);
void printDequeDeque(const deque<deque<int>>& dede1);
void printIntDeque(const deque<int>& de1);
void printPerDeDe(const vector<Person>& ve1, const deque<deque<int>>& dede1);
void setScore(vector<Person>& ve1, deque<deque<int>>& dede1);






int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	srand((unsigned int)time(NULL));
	vector<Person>ve1;
	deque<deque<int>>dede1;//所有老师对所有学生打的分都存在这个嵌套容器里
	createPerson(ve1);
	//printPersonVector(ve1);
	setScore(ve1, dede1);
	cout << "-----------------------------------------------------" << endl;
	cout << "排序，去掉最高分，去掉最低分后的打分：" << endl;
	printPerDeDe(ve1, dede1);
	cout << "-----------------------------------------------------" << endl;
	printPersonVector(ve1);
	//printPerDeDe(ve1, dede1);
	//printDequeDeque(dede1);
	//printIntDeque(dede1[0]);


}

void createPerson(vector<Person>& ve1)//创建5名选手，并保存在ve1（vector）容器中
{
	string nameSeed = "ABCDE";
	string::iterator it = nameSeed.begin();
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += (*it);
		int score = 0;
		Person p1(name, score);

		ve1.push_back(p1);
		it++;
	}
}

void printPersonVector(const vector<Person>& ve1)
{
	for (vector<Person>::const_iterator it = ve1.begin(); it != ve1.end(); it++)
	{
		cout << "选手：" << it->m_Name << "\t平均分数：" << it->m_Score << endl;
	}
}

void printIntDeque(const deque<int>& de1)
{
	for (deque<int>::const_iterator it = de1.begin(); it != de1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printDequeDeque(const deque<deque<int>>& dede1)
{
	for (deque<deque<int>>::const_iterator it1 = dede1.begin(); it1 != dede1.end(); it1++)
	{
		printIntDeque(*it1);
	}
	cout << endl;
}

void printPerDeDe(const vector<Person>& ve1, const deque<deque<int>>& dede1)
{
	deque<deque<int>>::const_iterator it1 = dede1.begin();
	for (vector<Person>::const_iterator it = ve1.begin(); it != ve1.end(); it++)
	{
		cout << "选手：" << it->m_Name << "\t打分：";
		printIntDeque(*it1);
		it1++;
	}
}

void setScore(vector<Person>& ve1, deque<deque<int>>& dede1)
{
	for (vector<Person>::iterator it = ve1.begin(); it != ve1.end(); it++)
	{
		deque<int>de2;
		for (int i = 0; i < 10; i++)
		{
			int Num1 = rand() % 41 + 60;
			de2.push_back(Num1);
		}
		dede1.push_back(de2);

	}

	cout << "原始打分：" << endl;
	printPerDeDe(ve1, dede1);

	vector<Person>::iterator it3 = ve1.begin();
	for (deque<deque<int>>::iterator it1 = dede1.begin(); it1 != dede1.end(); it1++)
	{

		sort((*it1).begin(), (*it1).end());
		(*it1).pop_back();
		it1->pop_front();

		int Num2 = 0;
		for (deque<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			Num2 += (*it2);
		}

		int Num3 = Num2 / (*it1).size();

		it3->m_Score = Num3;
		it3++;
	}


}