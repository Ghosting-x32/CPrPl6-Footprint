#include<iostream>
using namespace std;
const int Seasons = 4;
const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };
struct csjg
{
	double ar[Seasons];
};
void fill(csjg* pa);
void show(const csjg);





int main()
{
	csjg expenses;
	fill(&expenses);
	show(expenses);

	system("pause");
	return 0;
}

void fill(csjg* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->ar[i];
	}
}

void show(const csjg da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $";
		cout << da.ar[i] << endl;
		total += da.ar[i];
	}
	cout << "Total Expenses: $" << total << endl;
}