#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>






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


int sum(const initializer_list<int>& le1);




int main()
{
	initializer_list<int> app = { 1, 3, 5, 7, 9 };
	initializer_list<int> app1({ 2, 4, 6, 8 });

	cout << sum(app1) << endl;
	cout << sum({ 1, 3, 5, 7, 9 }) << endl;


	system("pause");
	return 0;
}


int sum(const initializer_list<int>& le1)
{
	int temp = 0;
	for (const auto& c : le1)
	{
		temp += c;
	}


	return temp;

}
