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
	vector<int> v1(10, 20);

	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	for (decltype(v1.size()) i = 0, sz = v1.size(); i != sz; ++i)
	{
		v1.push_back(v1[i]);
		//cout << sz << " ";
		//cout << v1.size() << " ";
	}
	//cout << endl;

	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}