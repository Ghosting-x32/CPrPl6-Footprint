#include<iostream>
#include<string>
#include"Sales_item.h"

int main()
{
	Sales_item item1(std::cin);
	Sales_item item2;
	std::cin >> item2;
	std::string bookisbn = "中国好书";
	Sales_item item3(bookisbn);
	std::cout << item3 << std::endl;
	item3 = item1 + item2;
	
	std::cout << item3 << std::endl;


	system("pause");
	return 0;
}