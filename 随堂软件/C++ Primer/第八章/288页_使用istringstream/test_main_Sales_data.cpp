#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>
#include<fstream>
#include<sstream>







using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;



struct PersonInfo
{
	string name;

	vector<string> phones;

};




int main()
{
	string line, word;
	vector<PersonInfo> people;

	while (getline(cin, line))
	{
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}

		people.push_back(info);

	}

	for (auto& c : people)
	{
		cout << c.name << endl;
		for (auto& d : c.phones)
		{
			cout << d << "\t";
		}
		cout << endl;
	}

	

	system("pause");
	return 0;
}








