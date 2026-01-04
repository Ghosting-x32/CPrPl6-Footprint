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







int main()
{
	char arr[] = "aaa";
	list<char*> li_aa(10, arr);

	for (const auto& c : li_aa)
	{
		cout << c << " ";
	}
	cout << endl;


	vector<string> ve_aa;

	ve_aa.assign(li_aa.begin(), li_aa.end());


	for (const auto& c : ve_aa)
	{
		cout << c << " ";
	}
	cout << endl;




	


	system("pause");
	return 0;
}








