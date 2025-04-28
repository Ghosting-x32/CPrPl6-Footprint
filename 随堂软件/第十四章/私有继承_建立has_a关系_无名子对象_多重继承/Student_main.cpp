#include<iostream>
#include<string>
#include<valarray>

#include"Student.h"

using namespace std;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{

	Student ada[pupils] = { Student(quizzes), Student(quizzes), Student(quizzes) };
	int i;
	for (i = 0; i < pupils; i++)
	{
		set(ada[i], quizzes);
	}

	cout << "\nStudent List:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << ada[i].Name() << endl;
	}

	cout << "\nResults:";
	for (i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;

	}




	system("pause");
	return 0;
}

void set(Student& sa, int n)
{
	cout << "Please enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz socores:\n";//数字全部一行输完，在输入流里面会自动流下去
	for (int i = 0; i < n; i++)
	{	
		while (!(cin >> sa[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

	}
	while (cin.get() != '\n')
	{
		continue;
	}

}