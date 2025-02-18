#include<iostream>
const int strsize = 30;
using namespace std;
struct bop 
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};
void tbts();

int main()
{
	cout << "Benevolent Order of Programmers Report\n";
	tbts();

	bop sjk[5] =
	{
		{"Wimp Macho", "wangzhe", "bopwm", 0},
		{"Raki Rhodes", "xingyao", "Junior Programmer", 2},
		{"Celia Laiter", "MIPS", "bopcl",1},
		{"Hoppy Hipman","zhuanshi", "Analyst Trainee", 2},
		{"Pat Hand", "LOOPY", "bopph", 1}
	};

	char choice;
	cout << "Enter your chioce: ";
	cin >> choice;
	while (choice != 'q')
	{
		switch (choice)
		{
		       case 'a':
		       {
			           cout << sjk[0].fullname << endl;
			           cout << sjk[1].fullname << endl;
			           cout << sjk[2].fullname << endl;
			           cout << sjk[3].fullname << endl;
			           cout << sjk[4].fullname << endl;
			           break;
		       }
			   case 'b':
			   {
				   cout << sjk[0].title << endl;
				   cout << sjk[1].title << endl;
				   cout << sjk[2].title << endl;
				   cout << sjk[3].title << endl;
				   cout << sjk[4].title << endl;
				   break;
			   }
			   case 'c':
			   {
				   cout << sjk[0].bopname << endl;
				   cout << sjk[1].bopname << endl;
				   cout << sjk[2].bopname << endl;
				   cout << sjk[3].bopname << endl;
				   cout << sjk[4].bopname << endl;
				   break;
			   }
			   case 'd':
			   {
				   cout << sjk[0].fullname << endl;
				   cout << sjk[1].bopname << endl;
				   cout << sjk[2].title << endl;
				   cout << sjk[3].bopname << endl;
				   cout << sjk[4].title << endl;
				   break;
			   }
			   default: 
			   {
				   cout << "请输入a,b,c,d或者q！\n";
				   tbts();
			   }
		}
		cout << "Next choice: ";
		cin >> choice;
	}
	cout << "Bye!\n";

	system("pause");
	return 0;
}

void tbts()
{
	cout << "a. display by name     b. display by title\n"
		"c. display by bopname      d. display by preference\n"
		"q. quit\n";
}

