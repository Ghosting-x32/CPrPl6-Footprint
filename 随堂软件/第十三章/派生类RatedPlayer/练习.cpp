#include <iostream>
#include<string>

#include"TableTennisPlayer.h"
#include"RatedPlayer.h"


using namespace std;


int main()
{
	TableTennisPlayer play1("Chuck", "Blizzard", true);
	RatedPlayer rplay1(1140, "Tara", "Boomdea", false);

	play1.Name();
	if (play1.HasTable())
	{
		cout << ": has a table.\n";
	}
	else
	{
		cout << ": hasn't a table\n";
	}

	rplay1.Name();
	if (rplay1.HasTable())
	{
		cout << ": has a table.\n";
	}
	else
	{
		cout << ": hasn't a table\n";
	}

	cout << "name: ";
	rplay1.Name();
	cout << "; Rating: " << rplay1.Rating() << endl;


	RatedPlayer rplay2(1212, play1);
	cout << "name: ";
	rplay2.Name();
	cout << "; Rating: " << rplay2.Rating() << endl;




	system("pause");
	return 0;
}
