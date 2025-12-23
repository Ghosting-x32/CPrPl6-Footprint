//#define NDEBUG//关闭调试状态
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





void print(vector<int> vInt, decltype(vInt.size()) index);

int main()
{
	vector<int> v1(10, 55);

	for (auto& c : v1)
	{
		cout << c << " ";
	}

	cout << endl;

	for (decltype(v1.size()) i = 0; i < 10; ++i)
	{
		v1[i] = i + 3;
	}






	print(v1, 0);
	cout << endl;
	print(v1, 0);
	cout << endl;


	system("pause");
	return 0;

}



/*

打开调试器时，每次递归调用print 函数都会输出“vector 对象的大小是：10”；
关闭调试器时，程序只输出vector 对象的内容，不再输出其大小。

*/
void print(vector<int> vInt, decltype(vInt.size()) index)
{
#ifndef NDEBUG

	cout << "\nvector 对象的大小是: " << vInt.size() << endl;

#endif // !NDEBUG




	if (!vInt.empty() && index < vInt.size())
	{
		cout << vInt[index] << " ";
		print(vInt, ++index);
	}

	return;

}




