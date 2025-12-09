#include<iostream>

using std::cout;
using std::endl;


int main()
{


	int a = 50;
	int sum = a;
	while (a < 100)
	{
		a++;
		
		sum += a;

	}
	
	cout << "sum = " << sum << endl;


	system("pause");
	return 0;
}