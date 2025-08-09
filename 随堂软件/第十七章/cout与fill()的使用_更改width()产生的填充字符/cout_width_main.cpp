#include<iostream>
#include<string>


using namespace std;

int main()
{
	cout.fill('*');
	//与字段宽度不同的是，新的填充字符将一直有效，直到更改它为止
	const char* staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper" };
	long bonus[2] = { 900, 1350 };

	for (int i = 0; i < 2; i++)
	{
		cout << staff[i] << ": $";
		cout.width(7);
		cout << bonus[i] << "\n";
	}


	cout.fill('+');
	cout.width(7);
	cout << 8 << endl;











	system("pause");
	return 0;
}