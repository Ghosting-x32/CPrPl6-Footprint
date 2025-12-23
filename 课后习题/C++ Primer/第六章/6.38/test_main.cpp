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

int odd[] = { 1, 3, 5, 7, 9 };
int even[] = { 0, 2, 4, 6, 8 };

auto arrPtr(int i) -> int(&)[5];
decltype(odd)& arrPtr1(int i);


int main()
{

	for (auto& c : arrPtr(3))
	{
		cout << c << " ";
	}

	cout << endl;

	auto& text_arr = arrPtr1(4);

	for (auto& c : text_arr)
	{
		cout << c << " ";
	}

	cout << endl;


	system("pause");
	return 0;

}

auto arrPtr(int i) -> int(&)[5]
{
	return (i % 2) ? odd : even;


}

decltype(odd)& arrPtr1(int i)
{
	return (i % 2) ? odd : even;

}