#include<iostream>
#include<string>
#include"Sales_item.h"

int main()
{
	Sales_item item1;
	Sales_item item2;
	int num = 1;
	while (std::cin >> item1)
	{
		
		if (compareIsbn(item2, item1) && item2.isbn().size() != 0)
		{
			num++;

		}
		else if (!compareIsbn(item2, item1) && item2.isbn().size() != 0)
		{
			std::cout << item2.isbn() << " 有 " << num << " 条销售记录" << std::endl;
			num = 1;


		}

		
		item2 = item1;

	}
	std::cout << item2.isbn() << " 有 " << num << " 条销售记录" << std::endl;
	
	//Sales_item trans1, trans2;
	//int num = 1;
	//std::cout << "请输入若干销售记录："
	//	<< std::endl;
	//if (std::cin >> trans1) {
	//	while (std::cin >> trans2)
	//		if (compareIsbn(trans1, trans2)) // ISBN 相同
	//			num++;
	//		else { // ISBN 不同
	//			std::cout << trans1.isbn() << "共有"
	//				<< num << "条销售记录" << std::endl;
	//			trans1 = trans2;
	//			num = 1;
	//		}
	//	std::cout << trans1.isbn() << "共有"
	//		<< num << "条销售记录" << std::endl;
	//}
	//else {
	//	std::cout << "没有数据" << std::endl;
	//	return -1;
	//}

	system("pause");
	return 0;
}