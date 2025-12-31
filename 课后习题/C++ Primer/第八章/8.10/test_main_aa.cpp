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








int main()
{
	std::ifstream input("ddd.txt");

	vector<string> vstr;
	string intxt, world;
	while (getline(input, intxt))
	{
		if (!intxt.empty())
		{
			vstr.push_back(intxt);
		}
	}

	for (auto& c : vstr)
	{
		std::istringstream istrput(c);
		while (istrput >> world)
		{
			cout << world << " ";
		}
		cout << endl;
		

	}
	




	

	system("pause");
	return 0;
}








