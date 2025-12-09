#include<iostream>
#include<vector>
#include<string>
#include<cctype>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;

int main()
{
	vector<int> v1(10);
	for (decltype(v1.size()) i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 1;

	}

	cout << "原始的各个元素是: " << endl;
	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	for (auto it = v1.begin(); it != v1.end(); it++)
	{
		(*it) *=  2;
	}


	cout << "每个元素变为原来的两倍后各个元素是: " << endl;
	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}