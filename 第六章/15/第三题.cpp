#include<iostream>
#include<cstdlib>
void cdqd();
using namespace std;
int main()
{
	cdqd();
	char ch;
	while (cin.get(ch))
	{
		cin.get();
		switch (ch)
		{
		    case 'c': 
		   {
			cout << "A maple is a carnivore.";
			system("pause");
			exit(0);
		   }
			case 'p' : 
			{
				cout << "A maple is a pianist.";
				system("pause");
				exit(0);
			}
			case 't' : 
			{
				cout << "A maple is a tree.";
				system("pause");
				exit(0);
			}
			case 'g': 
			{
				cout << "A maple is a game.";
				system("pause");
				exit(0);
			}
			default: 
			{
				cout << "Please enter a c,p,t,or g: ";
			}
		}
	}

	system("pause");
	return 0;
}

void cdqd()
{
	cout << "Please enter one of the following choices:" << endl;
	cout << "c) carnivore p) pianist\n"
		"t) tree g) game" << endl;
}