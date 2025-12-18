#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;




int main()
{
	const vector<string> scores = { "B", "A" };

	string lettergrade;
	int grade = 0;
	cout << "请输入你的分数（0-100）:" << endl;
	cin >> grade;

	if (grade >= 0 && grade <= 100)
	{
		lettergrade = (grade < 60 && grade >= 0) ? scores[0] : scores[1];
	}
	else
	{
		cout << "你输入的分数不在0-100范围内！" << endl;//grade > 100或者grade < 0时循环走这个分支
	}
	


	//if (grade < 60 && grade >= 0)
	//{
	//	lettergrade = scores[0];
	//}
	//else
	//{
	//	if (grade >= 60 && grade <= 100)
	//	{
	//		lettergrade = scores[1];

	//	}
	//	else
	//	{
	//		cout << "你输入的分数不在0-100范围内！" << endl;//grade > 100或者grade < 0时循环走这个分支
	//	}
	//}

	cout << lettergrade << endl;


	system("pause");
	return 0;
}