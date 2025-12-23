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

//1.常规写法返回指向数组的引用的函数
string(&text(int val))[10];

//2.使用别名的写法
typedef string arrT[10];
arrT& text1(int val);

//3.使用尾置返回类型的写法
auto text2(int val) -> string(&)[10];

//4.使用decltype的写法
decltype(arr)& text3(int val);



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

	auto& arr_text1 = text1(10);

	for (auto& c : arr_text1)
	{
		cout << c << "\n";
	}
	cout << endl;

	auto& arr_text2 = text2(7);

	for (auto& c : arr_text2)
	{
		cout << c << "\n";
	}
	cout << endl;


	auto& arr_text3 = text3(7);

	for (auto& c : arr_text3)
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

arrT& text1(int val)
{
	return (val % 2) ? arr : arr1;

}


auto text2(int val) -> string(&)[10]
{

	return (val % 2) ? arr : arr1;

}


decltype(arr)& text3(int val)
{
	return (val % 2) ? arr : arr1;

}