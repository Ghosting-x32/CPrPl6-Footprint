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

	//°æ±¾1	
	//using int_array = int[colCnt];
	////typedef int int_array[colCnt];
	//for (int_array& c : ia)
	//{
	//	for (int& d : c)
	//	{
	//		cout << d << "\t";
	//	}
	//	cout << endl;

	//}

	//°æ±¾2
	//using gx_size_t = size_t;
	//for (gx_size_t i = 0; i < rowCnt; i++)
	//{
	//	for (gx_size_t j = 0; j < colCnt; j++)
	//	{
	//		cout << ia[i][j] << "\t";
	//	}
	//	cout << endl;

	//}

	//°æ3
	using int_array = int[colCnt];
	using gx_int = int;
	for (int_array* p = begin(ia); p != end(ia); p++)
	{
		for (gx_int* q = begin(*p); q != end(*p); q++)
		{
			cout << *q << "\t";
 		}
		cout << endl;

	}







	system("pause");
	return 0;
}