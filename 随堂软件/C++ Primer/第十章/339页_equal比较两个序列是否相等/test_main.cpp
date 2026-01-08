#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<list>
#include<fstream>
#include<cstring>








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








int main()
{
	list<string> v1;
	string world;
	std::ifstream input("aaa.txt");
	while (input >> world)
	{
		v1.push_back(world);
	}

	input.close();
	//v1.pop_front();


	input.open("aaa.txt");
	vector<char*> v2;
	while (input >> world)
	{
		char* new_p = new char[world.size() + 1];
		strcpy_s(new_p, world.size() + 1, world.c_str());
		v2.push_back(new_p);
	}

	input.close();

	//v2.pop_back();

	//cout << (std::equal(v1.begin(), v1.end(), v2.begin()) ? "两个容器的内容相同" : "两个容器的内容不相同");
	cout << (std::equal(v2.begin(), v2.end(), v1.begin()) ? "两个容器的内容相同" : "两个容器的内容不相同");



	cout << endl;

	for (char* ptr : v2)
	{
		delete[] ptr;
		ptr = nullptr;

	}




	system("pause");
	return 0;
}


	















