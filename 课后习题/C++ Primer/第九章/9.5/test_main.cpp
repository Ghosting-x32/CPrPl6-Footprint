#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>




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



vector<int>::iterator func_aa(vector<int>::iterator beg, vector<int>::iterator end, int n);




int main()
{
	vector<int> ve_aa(10, 20);
	int aa_aa = 20;

	auto it_aa = func_aa(ve_aa.begin(), ve_aa.end(), aa_aa);
	if (it_aa == ve_aa.end())
	{
		cout << "容器中没有找到这个数: " << aa_aa << endl;
	}
	else
	{
		cout << "找到了你查找的数: " << *it_aa << endl;
	}

	

	

	

	system("pause");
	return 0;
}



vector<int>::iterator func_aa(vector<int>::iterator beg, vector<int>::iterator end, int n)
{
	vector<int>::iterator temp = end;
	for (auto it = beg; it != end; ++it)
	{
		if (*it == n && temp == end)
		{
			temp = it;
		}

	}



	return temp;
}




