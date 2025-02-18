#include<iostream>
#include<string>
int main()
{
	using namespace std;
	cout << "Enter words (to stop, type the word done)" << endl;
	string ch;
	int i = 0;
	while (ch != "done")
	{
		cin >> ch;
		++i;
	}
	cout << "You entered a total of " << i - 1 << " words.";



	cin.get();
	cin.get();
	return 0;
}