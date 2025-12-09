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
	constexpr size_t rowCnt = 3, colCnt = 4;

	int ia[rowCnt][colCnt] = {};

	for (size_t i = 0; i != rowCnt; i++)
	{
		for (size_t j = 0; j != colCnt; j++)
		{
			ia[i][j] = i * colCnt + j;
		}

	}

	//int (*p)[4] = ia;//p指向含有4个整数的数组
	//p = &ia[2];//p指向ia的尾元素


	using int_array = int[4];
	//typedef int int_array[4];

	for (int_array* p = ia; p != ia + 3; p++)
	{
		for (auto q = *p; q != *p + 4; q++)
		{
			cout << *q << "\t";
		}
		cout << endl;
	}











	system("pause");
	return 0;
}