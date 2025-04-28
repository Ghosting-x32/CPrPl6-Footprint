#include<iostream>
#include<string>


#include"Crab.h"
#include"Stack.h"

using namespace std;



int main()
{
	Crab<Stack> nebula;//Crab<Stack, int, double> nebula

	int ni;
	double nb;

	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
	
	flage:
	while (true)
	{
		while (!(cin >> ni >> nb))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Incorrect input, please enter a number!" << endl;
		}

		while (ni != 0 && nb != 0.0)
		{
			if ((nebula.push(ni, nb)))
			{
				goto flage;
			}

		}
		break;
	}
	

	while (nebula.pop(ni, nb))
	{
		cout << ni << ", " << nb << endl;
	}




	

	system("pause");
	return 0;
}