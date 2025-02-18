#include<iostream>
#include<ctime>
using namespace std;
int main()
{

	int ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " characters read\n";

	float secs = 6.0;
	clock_t delay = secs * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "done\a\n";

	cin.get();
	cin.get();
	return 0;
}