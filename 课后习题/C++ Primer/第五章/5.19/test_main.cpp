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
		cout << "please enter two string: ";
		string str1, str2;
		cin >> str1 >> str2;
		if (str1.size() >= str2.size())
		{
			cout << str2 << endl;
		}
		else
		{
			cout << str1 << endl;
		}


		cout << "\n\n" << "More? Enter yes or no: ";
		cin >> rsp;


	} while (!rsp.empty() && rsp[0] != 'n');



	system("pause");
	return 0;
}