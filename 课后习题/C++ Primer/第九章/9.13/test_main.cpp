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


/*


由于 list<int>与vector<double>是不同的容器类型，因此无法采用容器
拷贝初始化方式。但前者的元素类型是int，与后者的元素类型double 是相容的，
因此可以采用范围初始化方式来构造一个vector<double>，令它的元素值与
list<int>完全相同。对vector<int>也是这样的思路



*/





int main()
{
	list<int> li_aa(10, 20);
	vector<int> ve_bb(10, 30);

	vector<double> ve_aa(li_aa.begin(), li_aa.end());
	vector<double> ve_cc(ve_bb.begin(), ve_bb.end());

	for (const auto& c : ve_aa)
	{
		cout << c << " ";

	}
	cout << endl;
	for (const auto& c : ve_cc)
	{
		cout << c << " ";

	}


	cout << endl;


	system("pause");
	return 0;
}








