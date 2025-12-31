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




/*
解决方案  -->  属性  -->  调试  --> 命令参数

设置打开的文件名 aaa.txt(并且提前在该文件写入需要输入的数据：书号、销量、售价)
设置写入的文件名 bbb.txt

*/





int main(int argc, char* argv[])
{
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);

	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		while(read(input, trans))
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
	

	system("pause");
	return 0;
}








