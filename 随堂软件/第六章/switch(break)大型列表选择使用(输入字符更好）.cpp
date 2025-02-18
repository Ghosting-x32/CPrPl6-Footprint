#include<iostream>
using namespace std;
void showmenu();
void report();
void comfort();

int main()
{
	showmenu();
	char choice;
	cin >> choice;
	while (choice != 'Q' && choice != 'q')
	{
		switch (choice)
		{
		case 'a':
		case 'A':cout << "\a\n";
			break;
		case 'r':
		case 'R':report();
			break;
		case 'l':
		case 'L':cout << "The boos was in all day.\n";
			break;
		case 'c':
		case 'C':comfort();
			break;
		default: cout << "That's not a choice.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Bye!\n";

	cin.get();
	cin.get();
	return 0;
}


void showmenu()
{
	cout << "Please enter a, r, l, c, q:\n"
		"a) alarm              r) report\n"
		"l) alibi              c) comfort\n"
		"q) quit\n";
}

void report()
{
	cout << "It's been an excellent week for business.\n"
		"Aales are up 120%. Expenses are down 35%.\n";
}

void comfort()
{
	cout << "Your emp;oyess think you are the finest CEO\n"
		"in the industry. The board of directors think\n"
		"you are the finest CEOin the industry.\n";
}