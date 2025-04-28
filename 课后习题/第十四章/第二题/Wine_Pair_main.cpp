#include<iostream>
#include<string>
#include<valarray>


#include"Pair.h"
#include"Wine.h"


using namespace std;



int main()
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);

	cout << "Enter number of years: ";
	int yrs;

	while (!(cin >> yrs))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Incorrect input, please enter a number!" << endl;
	}

	while (cin.get() != '\n')
	{
		continue;
	}


	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;





	system("pause");
	return 0;
}










