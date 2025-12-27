#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>

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










int main()
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while(read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);

			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}

		print(cout, total) << endl;

	}
	else
	{
		cerr << "Nodata?!" << endl;

	}
	

	system("pause");
	return 0;
}








