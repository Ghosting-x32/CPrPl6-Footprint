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








int main()
{
	list<string> v1;
	string world;
	std::ifstream input("aaa.txt");
	while (input >> world)
	{
		v1.push_back(world);
	}




	auto sum = count(v1.begin(), v1.end(), "March");
	cout << "容器中共有: " << v1.size() << " 个元素!" << endl;
	cout << "March的个数是: ";
	cout << sum << endl;





	system("pause");
	return 0;
}


	















