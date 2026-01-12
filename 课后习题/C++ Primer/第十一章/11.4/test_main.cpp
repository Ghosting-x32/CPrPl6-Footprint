#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>//提供size_t
#include<algorithm>
#include<numeric>//提供算术的算法
#include<functional>//提供bind（多元谓词与一元谓词的转换）
#include<fstream>
#include<utility>//提供pair
#include<map>
#include<set>
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









int main()
{
	map<string, size_t> word_count;
	set<string> exclude = { "the", "but", "but", "and", "or", "an", "a",
							"The", "But", "And", "Or", "An", "A" };

	string word;
	while (cin >> word)
	{
		if (exclude.find(word) == exclude.end())
		{
			string temp_AA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string::size_type pos = 0;
			while ((pos = word.find_first_of(temp_AA, pos)) != string::npos)
			{
				word[pos] = std::tolower(word[pos]);
				++pos;
			}
			
		

			string temp = ".,";
			auto it = word.find_first_of(temp, 0);
		

			if (it == string::npos)
			{				
				++word_count[word];
			}
			else
			{
				word.erase(it);
				++word_count[word];
			}


			
		}

		
	}

	for (const auto& c : word_count)
	{
		cout << c.first << "\t" << c.second << endl;

	}


	for (const auto& c : exclude)
	{
		cout << c  << " ";

	}





	cout << endl;
	system("pause");
	return 0;
}



