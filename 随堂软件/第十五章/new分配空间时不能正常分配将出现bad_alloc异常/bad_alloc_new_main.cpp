#include<iostream>
#include<string>
#include<new>
#include<cstdlib>

using namespace std;


struct Big
{
	double stuff[200000];
};

int main()
{
	Big* pb;
	try
	{
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[100000];//在new中抛出异常类型为bad_alloc的异常
		cout << "Got past the new request:\n";


	}
	catch (bad_alloc& ba)//bad_alloc类从exception类公有派生而来
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);

	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;







	system("pause");
	return 0;
}