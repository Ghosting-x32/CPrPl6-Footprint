#include<iostream>
int main()
{
	using namespace std;
	cout << "Enter number of rows: ";
	int ch;
	cin >> ch;
	
	for (int i = 1; i <= ch ; ++i)
	{
			for (int k = 0; k < (ch - i); ++k)
			{
				cout << '.';
			}
			for (int j = 0; j < i; ++j)
			{
				cout << '*';
			}
			cout << endl;
	}

	cin.get();
	cin.get();
	return 0;
}