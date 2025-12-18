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
	vector<int> v;
	int i = 0;
	while (cin >> i)
	{
		v.push_back(i);
	}

	auto beg = v.begin();
	while (beg != v.end() && *beg >= 0)
	{
		++beg;
	}

	if (beg == v.end())
	{
		cout << "v里面没有小于0的元素!" << endl;
	}
	else
	{
		cout << "v里面第一个小于0的元素是: " << *beg << endl;
	}




	system("pause");
	return 0;
}