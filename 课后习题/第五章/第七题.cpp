#include<iostream>
#include<string>
using namespace std;

struct car
{
	string scs;
	int nf;
};

int main()
{
	cout << "How many cars do you wish to catalog?";
	int cs;
	cin >> cs;
	cin.get();
	car* zc = new car[cs];

	int i = 0;
	while (i < cs)
	{
		cout << "car #" << i + 1 << ":" << endl;
		cout << "Please enter the make:";
		getline(cin, zc[i].scs);
		cout << "Please enter the year made:";
		cin >> zc[i].nf;
		cin.get();
		++i;
	}

	cout << "Here is your collection:" << endl;

	int j = 0;
	while (j < cs)
	{
		cout << zc[j].nf << " " << zc[j].scs << endl;
		++j;
	}

	delete[] zc;

	cin.get();
	cin.get();
	return 0;
}