#include <iostream>
int main()
{
	using namespace std;
	long long qqu, us;
	cout << "Enter the world's population: ";
	cin >> qqu;
	cout << "Enter the population of the US: ";
	cin >> us;
	double bfb = double(us) / double(qqu) * 100;
	cout << "The population of the US is " << bfb << "% of the world population.";
	cin.get();
	cin.get();
	return 0;
}
