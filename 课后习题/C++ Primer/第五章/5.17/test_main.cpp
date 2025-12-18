#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;




int main()
{
	vector<int> v1 = { 0, 1, 1, 2 };
	vector<int> v2 = { 0, 1, 1, 2, 3, 5, 8 };
	vector<int> v3 = { 3, 5, 8 };
	vector<int> v4 = { 3, 5, 0, 9, 2, 7 };

	auto it1 = v1.begin();
	auto it2 = v2.begin();
	auto it3 = v3.begin();
	auto it4 = v4.begin();


	while (it1 != v1.end() && it2 != v2.end())
	{
		if (*it1 != *it2)
		{
			cout << "v1 和 v2之间不存在前缀关系" << endl;
			break;
		}
		
		++it1;
		++it2;


	}

	if (it1 == v1.end())
	{
		cout << "v1 是 v2的前缀" << endl;
	}

	if (it2 == v2.end())
	{
		cout << "v2 是 v1的前缀" << endl;
	}




	while (it3 != v3.end() && it4 != v4.end())
	{
		if (*it3 != *it4)
		{
			cout << "v3 和 v4之间不存在前缀关系" << endl;
			break;
		}
		
		++it3;
		++it4;


	}

	if (it3 == v3.end())
	{
		cout << "v3 是 v4的前缀" << endl;
	}

	if (it4 == v4.end())
	{
		cout << "v4 是 v3的前缀" << endl;
	}




	system("pause");
	return 0;
}