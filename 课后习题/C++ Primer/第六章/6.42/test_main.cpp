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
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;





string make_pllural(size_t ctr, const string& word, const string& ending = "s");


int main()
{
	string s1 = "success";
	string s2 = "failure";

	auto s3 = make_pllural(2, s1, "es");
	auto s4 = make_pllural(2, s2);

	auto s5 = make_pllural(1, s1, "es");
	auto s6 = make_pllural(1, s2);


	cout << "原stirng对象s1 = " << s1 << endl;
	cout << "s1的单数形式s5 = " << s5 << endl;
	cout << "s1的复数形式s3 = " << s3 << endl << endl;

	cout << "原stirng对象s2 = " << s2 << endl;
	cout << "s2的单数形式s6 = " << s6 << endl;
	cout << "s2的复数形式s4 = " << s4 << endl;


	system("pause");
	return 0;

}

string make_pllural(size_t ctr, const string& word, const string& ending)
{

	return (ctr > 1) ? word + ending : word;

}