#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;




int main()
{
	string rsp;

	do
	{
		cout << "please enter two values: ";
		int val1 = 0, val2 = 0;
		cin >> val1 >> val2;
		cout << "The sum of " << val1 << " and " << val2 << " = " << val1 + val2 << "\n\n" << "More? Enter yes or no: ";
		cin >> rsp;


	} while (!rsp.empty() && rsp[0] != 'n');



	system("pause");
	return 0;
}