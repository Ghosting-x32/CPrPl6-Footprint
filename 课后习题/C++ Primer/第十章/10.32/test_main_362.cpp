#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<algorithm>
#include<numeric>

#include"Sales_item_362.h"



int main()
{
	std::istream_iterator<Sales_item> item_iter(std::cin), eof;
	std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");

	std::vector<Sales_item> ve_sa(item_iter, eof);
	//std::copy(ve_sa.begin(), ve_sa.end(), out_iter);

	std::sort(ve_sa.begin(), ve_sa.end(), compareIsbn);

	//std::copy(ve_sa.begin(), ve_sa.end(), out_iter);

	if (!ve_sa.empty())
	{
		auto temp = ve_sa.begin();
		while (temp != ve_sa.end())
		{
			auto temp_aa = *temp;

			auto r = std::find_if(temp + 1, ve_sa.end(),
				[temp_aa](const Sales_item& sa)
				{
					return sa.isbn() != temp_aa.isbn();
				}
			);

			*out_iter++ = std::accumulate(temp + 1, r, temp_aa);


			temp = r;

		}



	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		//	return -1;
	}


	std::cout << std::endl;



	system("pause");
	return 0;
}