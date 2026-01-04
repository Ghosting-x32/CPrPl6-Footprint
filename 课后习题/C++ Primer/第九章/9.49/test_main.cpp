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
	string str1("abcdefghijklmnopqrstuvwxyz");
	string str_bf("bdfhklt");//上出头
	string str_gp("gjpqy");//下出头
	string str_bf_gp = str_bf + str_gp;
	string world;

	std::ifstream input("abc.txt");
	string::size_type pos = 0;

	while (input >> world)
	{
		
		if ((pos = world.find_first_of(str_bf_gp, 0)) == string::npos)
		{
			cout << world << "\t";
		}

	}

	input.close();

	cout << endl;


	system("pause");
	return 0;
}















