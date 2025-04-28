#include<iostream>
#include<string>


#include"beta.h"

using namespace std;



int main()
{
	
	beta<double>guy(3.5, 3);//T->double
	cout << "T was set to double\n";
	guy.Show();
	cout << "Vwas set to T, which is double, then Vwas set to int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U was  set to int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n";



	

	system("pause");
	return 0;
}