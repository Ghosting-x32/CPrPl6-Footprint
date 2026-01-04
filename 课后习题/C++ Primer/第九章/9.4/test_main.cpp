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



bool func_aa(vector<int>::iterator beg, vector<int>::iterator end, int n);




int main()
{
	vector<int> ve_aa(10, 20);
	int aa_aa = 30;

	if (func_aa(ve_aa.begin(), ve_aa.end(), aa_aa))
	{
		cout << "容器中存在这个数: " << aa_aa << endl;
	}
	else
	{
		cout << "容器中不存在这个数: " << aa_aa << endl;
	}

	

	

	

	system("pause");
	return 0;
}



bool func_aa(vector<int>::iterator beg, vector<int>::iterator end, int n)
{
	bool temp = false;
	for (auto it = beg; it != end; ++it)
	{
		if (*it == n && temp == false)
		{
			temp = true;
		}

	}



	return temp;
}




