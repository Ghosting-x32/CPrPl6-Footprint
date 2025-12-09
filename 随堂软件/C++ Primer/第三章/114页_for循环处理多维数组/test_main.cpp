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

	for (auto& c : ia)
	{
		for (auto& d : c)
		{
			cout << d << "\t";
		}
		cout << endl;

	}








	system("pause");
	return 0;
}