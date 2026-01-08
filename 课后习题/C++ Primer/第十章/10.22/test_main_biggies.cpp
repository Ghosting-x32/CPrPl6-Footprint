#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<list>
#include<fstream>
#include<functional>









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
void biggies(vector<string>& words, vector<string>::size_type sz);
bool check_size(const string& s, string::size_type sz);



int main()
{
	vector<string> v1;
	string temp;
	std::ifstream input("aaa.txt");
	while (input >> temp)
	{
		v1.push_back(temp);

	}
	std::for_each(v1.begin(), v1.end(),
		[](const string& s)
		{
			cout << s << " ";
		}
	);
	cout << endl;

	biggies(v1, 5);





	cout << endl;
	system("pause");
	return 0;
}

bool check_size(const string& s, string::size_type sz_aa)
{
	return s.size() >= sz_aa;
}





void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);

	std::stable_sort(words.begin(), words.end(),
		[](const string& s1, const string& s2)
		{
			return s1.size() < s2.size();
		}
	);

	auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));//在一个需要一元谓词的地方，硬是用多元谓词的办法

	//auto wc = std::stable_partition(words.begin(), words.end(),
	//	[sz](const string& s)
	//	{
	//		return s.size() >= sz;
	//	}
	//);





	auto acount = words.end() - wc;
	//auto acount = std::count_if(words.begin(), words.end(),
	//	[sz](const string& s)
	//	{
	//		return s.size() >= sz;
	//	}
	//);

	cout << acount << " 个单词长度大于或等于: " << sz << endl;

	std::for_each(wc, words.end(),
		[](const string& s)
		{

			cout << s << " ";
		}
	);
	cout << endl;

}







void elimDups(vector<string>& words)
{
	std::sort(words.begin(), words.end());
	//for (const auto& c : words)
	//{
	//	cout << c << " ";
	//}
	//cout << endl;
	auto end_unique = std::unique(words.begin(), words.end());
	//cout << words.size() << endl;
	//cout << words[9] << endl;
	//for (const auto& c : words)
	//{
	//	cout << c << " ";
	//}
	//cout << endl;
	//vector<string>::iterator end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());


}

















































































