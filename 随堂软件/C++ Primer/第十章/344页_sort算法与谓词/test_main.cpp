#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
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







void elimDups(vector<string>& words);
bool isShorter(const string& s1, const string& s2);



int main()
{
	vector<string> v1;
	string temp;
	std::ifstream input("aaa.txt");
	while (input >> temp)
	{
		v1.push_back(temp);

	}
	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	elimDups(v1);

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}



bool isShorter(const string& s1, const string& s2)
{

	return s1.size() < s2.size();

}



void elimDups(vector<string>& words)
{
	std::sort(words.begin(), words.end(), isShorter);
	for (const auto& c : words)
	{
		cout << c << " ";
	}
	cout << endl;
	auto end_unique = std::unique(words.begin(), words.end());
	cout << words.size() << endl;
	cout << words[9] << endl;
	for (const auto& c : words)
	{
		cout << c << " ";
	}
	cout << endl;
	//vector<string>::iterator end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());


}

































