#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>//提供size_t
#include<algorithm>
#include<numeric>//提供算术的算法
#include<functional>//提供bind（多元谓词与一元谓词的转换）
#include<fstream>
#include<sstream>
#include<utility>//提供pair
#include<map>
#include<set>
#include<list>
#include<cctype>







using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::map;
using std::set;
using std::list;
using std::pair;



const string& transform(const string& s, const std::unordered_map<string, string>& m);
std::unordered_map<string, string> buildMap(std::ifstream& map_file);
void word_transform(std::ifstream& map_file, std::ifstream& input);


int main()
{
	std::ifstream input1("aaa.txt");
	std::ifstream input2("bbb.txt");


	word_transform(input1, input2);




	cout << endl;
	system("pause");
	return 0;
}


const string& transform(const string& s, const std::unordered_map<string, string>& m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
	{
		return map_it->second;
	}
	else
	{
		return s;
	}

}


std::unordered_map<string, string> buildMap(std::ifstream& map_file)
{
	std::unordered_map<string, string> trans_map;
	string key;
	string value;

	while (map_file >> key && getline(map_file, value))
	{
		trans_map[key] = value.substr(1);

	}
	return trans_map;

}

void word_transform(std::ifstream& map_file, std::ifstream& input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		std::istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}

		cout << endl;

	}


}