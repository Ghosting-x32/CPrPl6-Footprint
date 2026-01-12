#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>
#include<map>
#include<set>

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





bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs);




int main()
{
	//方法1
	std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(&compareIsbn);//用函数地址和函数名初始化效果相同，函数名会转换为函数指针（函数地址）

	
	std::multiset<Sales_data, bool(*)(const Sales_data& lhs, const Sales_data& rhs)>::iterator it = bookstore.begin();
	//std::multiset<Sales_data, decltype(compareIsbn)*>::iterator it = bookstore.begin();
	//auto it = bookstore.begin();



	



	/*
		std::multiset<Sales_data, decltype(compareIsbn)> bookstore(compareIsbn);//类型设置成函数类型，对应初始化时就不能传指针，只能传函数名（1）
	//方法2
	std::multiset<Sales_data, bool(*)(const Sales_data& lhs, const Sales_data& rhs)> bookstore(compareIsbn);//（1）
	std::multiset<Sales_data, bool(*)(const Sales_data& lhs, const Sales_data& rhs)> bookstore(compareIsbn);//最原始指定类型是函数指针的形式
	//方法3
	using pf = bool(const Sales_data& lhs, const Sales_data& rhs);
	std::multiset<Sales_data, pf> bookstore(compareIsbn);//（1）

	using pf1 = bool(*)(const Sales_data& lhs, const Sales_data& rhs);
	std::multiset<Sales_data, pf1> bookstore(compareIsbn);

	//方法4（答案）
	typedef bool (*pd)(const Sales_data&, const Sales_data&);
	std::multiset<Sales_data, pf> bookstore(compareIsbn);

	//取别名用函数指针类型和函数类型效果一样
	typedef bool (pd1)(const Sales_data&, const Sales_data&);
	std::multiset<Sales_data, pf> bookstore(compareIsbn);//（1）



	std::multimap<Sales_data, int ,decltype(compareIsbn)*> bookstore(&compareIsbn);//用在map上也是一样的道理

	*/










	//Sales_data total(cin);
	//if (cin)
	//{
	//	Sales_data trans(cin);
	//	do
	//	{
	//		if (total.isbn() == trans.isbn())
	//		{
	//			total.combine(trans);

	//		}
	//		else
	//		{
	//			print(cout, total) << endl;
	//			total = trans;
	//		}
	//	}while (read(cin, trans));

	//	print(cout, total) << endl;

	//}
	//else
	//{
	//	cerr << "Nodata?!" << endl;

	//}
	

	system("pause");
	return 0;
}



bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}




