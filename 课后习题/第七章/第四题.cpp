#include<iostream>
long double probability(unsigned numbers, unsigned picks);
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	double total, choices, total1, choices1;
	long double dx, xx;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed:(两组几选几）\n";
	while ((cin >> total >> choices >> total1 >> choices1) && choices <= total && choices1 <= total1)
	{
		dx = probability(total, choices);
		xx = probability(total1, choices1);

		cout << "You have one chance in ";
		cout << dx * xx;
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit)";
	}

	system("pause");
	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;

	return result;
}
