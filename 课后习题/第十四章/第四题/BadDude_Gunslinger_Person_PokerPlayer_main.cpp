#include<iostream>
#include<string>
#include<random>


#include"BadDude.h"
#include"Gunslinger.h"
#include"Person.h"
#include"PokerPlayer.h"
#include"Card.h"

using namespace std;

const int SIZE = 5;

int main()
{

	


	Person* lolas[SIZE];


	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n";
		cout << "g: Gunslinger p: PokerPlayer b: BadDude q: quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Input error, please re-enter!" << endl;
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;

		}

		switch (choice)
		{
		case 'g':
			lolas[ct] = new Gunslinger;
			break;
		case 'p':
			lolas[ct] = new PokerPlayer;
			break;
		case 'b':
			lolas[ct] = new BadDude;
			break;
		case 'q':
			goto flage;
			break;
		default:
			break;
		}

		while (cin.get() != '\n')
		{
			continue;
		}

		lolas[ct]->Set();

	}

flage:
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
	{
		//cout << "hhh" << endl;
		delete lolas[i];//指向父类的指针可以释放子类对象，前提是父类析构函数是虚函数

	}






	system("pause");
	return 0;
}