#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<functional>
#include<list>
#include<fstream>









using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::count;
using std::list;





bool check_size(const string& s, string::size_type sz);





int main()
{
	string str("aaa");
	vector<int> v1_ve;
	for (vector<int>::size_type i = 0; i < 10; ++i)
	{
		v1_ve.push_back(i);
	}

	std::for_each(v1_ve.begin(), v1_ve.end(),
		[](const int& aa)
		{
			cout << aa << " ";
		}
	);
	cout << endl;

	auto it = std::find_if(v1_ve.begin(), v1_ve.end(), std::bind(check_size, str , std::placeholders::_1));

	if (it != v1_ve.end())
	{
		cout << "第一个大于string长度的值是: " << *it << endl;
	}
	else
	{
		cout << "没有找到大于string长度的值！！！" << endl;
	}
	

	cout << endl;
	system("pause");
	return 0;
}


bool check_size(const string& s, string::size_type sz)
{

	return s.size() <= sz;
}