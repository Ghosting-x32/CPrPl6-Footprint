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
	for (decltype(v1.size()) i = 0; i < 10; ++i)
	{
		v1.push_back(i);

	}
	cout << "v1的源素数据(所有)是: " << endl;
	for (auto& c : v1)
	{

		cout << c << "\t";

	}

	cout << endl;

	cout << "v1里面的所有奇数是: " << endl;
	for (auto& c : v1)
	{
		if (c % 2 != 0)
		{
			cout << c << "\t";

		}
	}
	cout << endl;

	cout << "奇数部分翻倍之后v1的数据是(所有):" << endl;
	for (auto& c : v1)
	{

		cout << (c % 2 == 0 ? c : c = c * 2) << "\t";

	
	}



	cout << endl;






	system("pause");
	return 0;
}