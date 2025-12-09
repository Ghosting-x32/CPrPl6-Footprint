#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	
	int arr[10] = {};

	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i;
	}


	vector<int> v1(begin(arr), end(arr));
	for (auto& c : v1)
	{
		cout << c << " ";
	}

	cout << endl;

	vector<int> v2(arr + 2, arr + 9);

	for (auto& c : v2)
	{
		cout << c << " ";
	}

	cout << endl;



	system("pause");
	return 0;
}