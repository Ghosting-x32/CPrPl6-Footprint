#include<iostream>
#include<cstdlib>
#include<ctime>
#include"string1.h"

const int ArSize = 10;
const int MaxLen = 81;



int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	String name;
	cout << "Hi, what's your name?\n>> ";
	cin >> name;

	cout << name << ", please enter up to " << ArSize
		<< " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (int i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		String* shortest = & sayings[0];
		String* first = & sayings[0];
		for (int i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest -> length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "Shortes saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;
		cout << "This program used " << String::HowMany()
			<< " String objects.Bye.\n";

		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "Not much to say, eh?\n"
		<< "No input! Bye.\n";

	cout << "Bye.\n";


	system("pause");
	return 0;
}

