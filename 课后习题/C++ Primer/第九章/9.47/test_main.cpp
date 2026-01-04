#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>





using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::list;
using std::deque;
using std::forward_list;






int main()
{
	string str1("ab2c3d7R4E6");
	string numbers("0123456789");
	string str_abc("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	string::size_type pos = 0;

	while ((pos = str1.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "查找到数字 " << str1[pos] << " 在 " << pos << " 下标位置！" << endl;
		++pos;

	}
	
	pos = 0;
	cout << endl;
	while ((pos = str1.find_first_of(str_abc, pos)) != string::npos)
	{
		cout << "查找到字母 " << str1[pos] << " 在 " << pos << " 下标位置！" << endl;
		++pos;

	}


	pos = 0;
	cout << endl;
	while ((pos = str1.find_first_not_of(str_abc, pos)) != string::npos)
	{
		cout << "查找到数字 " << str1[pos] << " 在 " << pos << " 下标位置！" << endl;
		++pos;

	}

	pos = 0;
	cout << endl;
	while ((pos = str1.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << "查找到字母 " << str1[pos] << " 在 " << pos << " 下标位置！" << endl;
		++pos;

	}
	cout << endl;


	system("pause");
	return 0;
}















