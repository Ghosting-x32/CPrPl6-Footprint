#include<iostream>
#include<string>
#include<cctype>

#include"Stack.h"

using namespace std;

int main()
{
	Stack<string>st;
	char ch;
	string po;
	cout << "Please enter A to add a purchase order,\n";
	cout << "p to process a PO, or Q to quit.\n";

	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}

		if (!isalpha(ch))
		{
			cout << '\a';
			cout << "Input error, please enter letters!" << endl;
			continue;
		}

		switch (ch)
		{
		case 'a':
		case 'A':
		{
			cout << "Enter a PO number to add: ";
			cin >> po;

			if (st.isfull())
			{
				cout << "stack already full\n";
			}
			else
			{
				st.push(po);
			}

		}
			break;

		case 'p':
		case 'P':
		{
			if (st.isempty())
			{
				cout << "stack already empty\n";
			}
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped\n";
			}


		}
			break;

		default:
		{
			cout << "\a";
			cout << "Input error, please re-enter!" << endl;
			cout << "Please enter a, A, p, P, q, Q: " << endl;
		}
			break;
		}


		cout << "Please enter A to add a purchase order,\n";
		cout << "p to process a PO, or Q to quit.\n";



	}






	system("pause");
	return 0;
}