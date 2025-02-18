#include <iostream>
void mice(int);
void run(int);
using namespace std;
int main()
{
	mice(1);
	mice(2);
	run(3);
	run(4);
	cin.get();
	cin.get();
	return 0;
}

void mice(int n)
{
	cout << "Three blind mice\n";
}

void run(int m)
{
	cout << "See how they run\n";
}