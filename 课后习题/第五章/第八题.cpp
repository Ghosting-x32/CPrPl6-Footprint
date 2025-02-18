#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	cout << "Enter words (to stop, type the word done)" << endl;
	char* ch = new char[20];
	int i = 0;
	while (strcmp(ch, "done"))
	{
		cin >> ch;
		++i;
	}
	cout << "You entered a total of " << i - 1 << " words.";


	delete[] ch;
	cin.get();
	cin.get();
	return 0;
}