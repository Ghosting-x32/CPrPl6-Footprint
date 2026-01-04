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



bool li_V_ve(const list<int>& li, const vector<int>& ve);



int main()
{
	list<int> li_aa(10, 10);
	vector<int> ve_aa(10, 10);


	if (li_V_ve(li_aa, ve_aa))
	{

		cout << "两个容器相等" << endl;
	}
	else
	{
		cout << "哦哟！！！两个容器不相等" << endl;

	}
	


	system("pause");
	return 0;
}


bool li_V_ve(const list<int>& li, const vector<int>& ve)
{
	bool temp = true;
	if (li.size() != ve.size())
	{
		temp = false;
	}
	else
	{
		auto lib = li.cbegin();
		auto lie = li.cend();
		auto veb = ve.cbegin();

		for (; lib != lie; ++veb, ++lib)
		{
			if (*lib != *veb && temp == true)
			{
				temp = false;
			}
		}

	}





	return temp;

}





