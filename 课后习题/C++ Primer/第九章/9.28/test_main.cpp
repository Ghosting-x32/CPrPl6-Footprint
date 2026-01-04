#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>





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
using std::forward_list;



void strForwli(forward_list<string>& foli, const string& str1, const string& str2);



int main()
{
	forward_list<string> fowali_aa = { "aaa", "bbb", "ccc", "aaa", "ggg"};
	string str_aa = "aaa";
	string str_ee = "eee";
	string str_dd = "ddd";

	strForwli(fowali_aa, str_aa, str_dd);
	for (const auto& c : fowali_aa)
	{
		cout << c << " ";
	}
	cout << endl;

	strForwli(fowali_aa, str_ee, str_dd);
	for (const auto& c : fowali_aa)
	{
		cout << c << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}

void strForwli(forward_list<string>& foli, const string& str1, const string& str2)
{

	auto perv = foli.before_begin();
	auto curr = foli.begin();
	bool find = false;
	while (curr != foli.end())
	{//当前判断条件是在链表中所有与str1相等的元素后面都插入str2
		if (*curr == str1)//*curr == str1 && find == false-----这个作为判断的话，只在第一次找到str1的对应元素后面插入str2
		{
			curr = foli.emplace_after(curr, str2);
			find = true;
		}
		else
		{
			perv = curr;
			++curr;
		}

	}
	if (find != true)
	{
		foli.emplace_after(perv, str2);
	}
	

}






