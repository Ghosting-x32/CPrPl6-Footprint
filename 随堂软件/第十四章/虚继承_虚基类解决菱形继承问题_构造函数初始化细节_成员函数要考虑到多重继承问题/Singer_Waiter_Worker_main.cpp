#include<iostream>
#include<string>
#include<cstring>

#include"Singer.h"
#include"Waiter.h"
#include"Worker.h"
#include"SingingWaiter.h"

using namespace std;

const int SIZE = 5;

int main()
{
	Worker* lolas[SIZE];


	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n";
		cout << "w: waiter s: singer t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Input error, please re-enter!" << endl;
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;

		}

		switch (choice)
		{
		case 'w':
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
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
		delete lolas[i];

	}





	system("pause");
	return 0;
}