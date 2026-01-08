#include<iostream>
#include<string>
#include<iterator>
#include"Sales_item_362.h"

int main()
{
	std::istream_iterator<Sales_item> item_iter(std::cin), eof;
	std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");



	Sales_item total = *item_iter++;

	if (item_iter != eof)
	{
		
		while (item_iter != eof)
		{
			if (item_iter -> isbn() == total.isbn())
			{
				total += *item_iter++;
			}
			else
			{			
				*out_iter++ = total;
				total = *item_iter++;
			}
			
			

		}
		*out_iter++ = total;

	}
	else 
	{
		std::cerr << "No data?!" << std::endl;
		return -1;

	}
	 



	system("pause");
	return 0;
}