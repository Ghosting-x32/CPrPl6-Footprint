#include<iostream>
#include<string>
#include"Sales_item.h"

int main()
{
	std::string v1 = "ggggg";
//共有5个构造函数
	//1.默认构造函数
	Sales_item book;
	//2.接受一个istream对象引用形参的构造函数
	//Sales_item book1(std::cin);
	//3.接受一个char*类型形参的构造函数（char*自动转换为string）
	Sales_item book3("hhhh");//-----这两个走同一个构造函数
	//3..接受一个string类型引用形参的构造函数
	Sales_item book4(v1);//-------这两个走同一个构造函数
//其次还有程序自动提供的4.复制构造函数和5.移动构造函数
	//std::cin >> book;
	//std::cout << book << std::endl;
	//std::cout << book1 << std::endl;
	std::cout << book3 << std::endl;
	std::cout << book4 << std::endl;



	system("pause");
	return 0;
}