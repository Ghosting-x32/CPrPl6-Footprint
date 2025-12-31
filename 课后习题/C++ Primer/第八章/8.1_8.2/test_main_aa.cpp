#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>







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




std::istream& get_is_aaa(std::istream& is);





int main()
{
	
	get_is_aaa(cin);



	
	

	system("pause");
	return 0;
}



std::istream& get_is_aaa(std::istream& is)
{
	auto old_state = is.rdstate();
	is.clear();

	string temp;

	while (is >> temp)
	{
		cout << temp << endl;
	}


	is.setstate(old_state);
	return is;

}
