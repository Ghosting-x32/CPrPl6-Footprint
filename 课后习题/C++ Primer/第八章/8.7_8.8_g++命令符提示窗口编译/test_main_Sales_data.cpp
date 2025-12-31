#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>
#include<fstream>
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








int main(int argc, char* argv[])
{
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2], std::ofstream::app);


	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);

			}
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}

		print(output, total) << endl;

	}
	else
	{
		cerr << "Nodata?!" << endl;

	}
	input.close();
	output.close();

	system("pause");
	return 0;
}








