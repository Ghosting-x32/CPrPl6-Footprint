#include <iostream>
#include<string>

#include"TableTennisPlayer.h"


using namespace std;


int main()
{
	TableTennisPlayer play1("Chuck", "Blizzard", true);
	TableTennisPlayer play2("Tara", "Boomdea", false);
	play1.Name();
	if (play1.HasTable())
	{
		cout << ": has a table.\n";
	}
	else
	{
		cout << ": hasn't a table\n";
	}

	play2.Name();
	if (play2.HasTable())
	{
		cout << ": has a table.\n";
	}
	else
	{
		cout << ": hasn't a table\n";
	}


	system("pause");
	return 0;
}
