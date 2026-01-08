#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>
#include<algorithm>
#include<numeric>

#include"Sales_data.h"





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




bool comparIsbn(const Sales_data& sa1, const Sales_data& sa2);





int main()
{
	vector<Sales_data> v1;

	Sales_data sa_jjj("jjj", 10, 20.3);
	Sales_data sa_ggg("gggg", 20, 22.3);
	Sales_data sa_aaa("aaa", 30, 26.3);
	Sales_data sa_ccc("cccc", 40, 29.3);
	Sales_data sa_bbb("bbb", 50, 28.3);
	v1.push_back(sa_jjj);
	v1.push_back(sa_ggg);
	v1.push_back(sa_aaa);
	v1.push_back(sa_ccc);
	v1.push_back(sa_bbb);

	for (const auto& c : v1)
	{
		print(cout, c);
		cout << endl;
	}

	cout << "*************************************" << endl;
	std::stable_sort(v1.begin(), v1.end(), comparIsbn);
	
	//std::sort(v1.begin(), v1.end(), comparIsbn);
	for (const auto& c : v1)
	{
		print(cout, c);
		cout << endl;
	}
	

	system("pause");
	return 0;
}


bool comparIsbn(const Sales_data& sa1, const Sales_data& sa2)
{
	return sa1.isbn() < sa2.isbn();

}





