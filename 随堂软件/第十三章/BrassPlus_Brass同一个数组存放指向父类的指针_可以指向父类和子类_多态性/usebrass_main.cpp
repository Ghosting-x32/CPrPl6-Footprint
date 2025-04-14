#include <iostream>
#include<string>

#include"Brass.h"
#include"BrassPlus.h"


using namespace std;

const int CLIENTS = 4;

typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

int main()
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass* p_clients[CLIENTS];//储存指向父类的指针的数组
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name:";
		getline(cin, temp);
		cout << "Enter client's account number:";
		while (!(cin >> tempnum))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Incorrect input, please enter a number!" << endl;
		}
		cout << "Enter opening balance: $";
		while (!(cin >> tempbal))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Incorrect input, please enter a number!" << endl;
		}

		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
		{
			cout << "Enter either 1 or 2: ";
			while (cin.get() != '\n')
			{
				continue;
			}
		}

		while (cin.get() != '\n')
		{
			continue;
		}

		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, tempnum, tempbal);
			continue;
		}
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			while (!(cin >> tmax))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "Incorrect input, please enter a number!" << endl;
			}
			cout << "Enter the intersest rate "
				<< "as a decimal fraction: ";

			while (!(cin >> trate))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "Incorrect input, please enter a number!" << endl;
			}
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);

		}
		while (cin.get() != '\n')
		{
			continue;
		}

	}
	cout << endl;


	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}


	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}








	restore(initialState, prec);

	system("pause");
	return 0;
}


format setFormat()
{
	return cout.setf(ios_base::fixed, ios_base::floatfield);
}


void restore(format f, precis p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}