#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>
#include<fstream>

#include"MyTime.h"





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
	MyTime tie;
	tie.print();

	MyTime tie1("January 1,1990");
	tie1.print();

	MyTime tie4("January 12,1990");
	tie4.print();

	MyTime tie2("Jan 1 1990");
	tie2.print();

	MyTime tie5("Jan 12 1990");
	tie5.print();

	MyTime tie3("29/12/1990");
	tie3.print();

	system("pause");
	return 0;
}















