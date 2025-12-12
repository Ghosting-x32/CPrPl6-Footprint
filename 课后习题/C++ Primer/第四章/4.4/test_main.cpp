#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	/*
	添加括号之后的形式应该是(( 12 / 3 ) * 4 ) +( 5 * 15 ) + (( 24 %
	4 ) / 2 )，求值的过程是：首先计算12/3 得到4，接着4*4 得到16，同时计算
	5*15 得到75，计算24%4 得到0，接着计算0/2 得到0，最后执行加法运算16+75+0
	得到91。最终的计算结果是91。
	*/
	//((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
	auto a = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;


	cout << a << endl;






	system("pause");
	return 0;
}