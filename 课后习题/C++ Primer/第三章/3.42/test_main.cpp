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
	vector<int> v1;
	for (decltype(v1.size()) i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}

	int arr[10] = {};

	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = v1[i];
	}

	for (auto& c : arr)
	{
		cout << c << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}