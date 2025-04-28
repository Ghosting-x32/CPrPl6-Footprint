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
		pb = new Big[100000];//��new���׳��쳣����Ϊbad_alloc���쳣
		cout << "Got past the new request:\n";


	}
	catch (bad_alloc& ba)//bad_alloc���exception�๫����������
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