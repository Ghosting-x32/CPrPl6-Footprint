#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>
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
using std::list;
using std::deque;
using std::forward_list;






int main()
{
	vector<string> v1 = { "21", "25", "36", "96" };
	vector<string> v2 = { "13.22", "58.01", "89.32", "42.12" };

	int a = 200;
	string a_a = std::to_string(a);

	cout << a_a << endl;



	int sum = 0;
	for (const auto& c : v1)
	{
		sum += std::stoi(c);

	}
	cout << sum << endl;


	double sum1 = 0;
	for (const auto& c : v2)
	{
		sum1 += std::stod(c);
	}

	cout << sum1 << endl;

	system("pause");
	return 0;
}















