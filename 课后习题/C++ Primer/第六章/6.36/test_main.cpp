#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;



string arr[10] = {};
string arr1[10] = {};

string(&text(int val))[10];


int main()
{


	for (string::size_type i = 0; i < 10; ++i)
	{
		arr[i] = (arr[i] + static_cast<char>('a' + i)) + "******";
	}

	for (string::size_type i = 0; i < 10; ++i)
	{
		arr1[i] = (arr1[i] + static_cast<char>('A' + i)) + "******";
	}


	for (auto& c : arr)
	{
		cout << c << "\n";
	}
	cout << endl;

	for (auto& c : arr1)
	{
		cout << c << "\n";
	}
	cout << "======================================" << endl << endl;

	auto& arr_text = text(9);

	for (auto& c : arr_text)
	{
		cout << c << "\n";
	}
	cout << endl;








	system("pause");
	return 0;

}

string(&text(int val))[10]
{
	return (val % 2) ? arr : arr1;
}





