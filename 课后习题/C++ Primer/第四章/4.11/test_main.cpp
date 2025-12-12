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
	要想用一条表达式测试a、b、c、d 的关系，并确保a 大于b、b 大于c、c 大
于d，应该写成：
a > b && b > c && c > d
切勿写成：
a > b > c > d
因为关系运算符满足左结合律且运算的结果是布尔值，所以把几个关系运算符
连写在一起必然会产生意想不到的结果。a > b > c > d 的实际求值过程是先判
断a > b 是否成立，成立则为1，不成立则为0；接着用这个布尔值（1 或0）与c
比较，所得的结果仍然是一个布尔值；最后再用刚刚得到的布尔值与d 进行比较。
显然这一过程与用户的书写原意背道而驰。

	*/
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;

	if (a > b && b > c && c > d)
	{

		cout << "最大的是 " << a << endl;
		cout << "最小的是 " << d << endl;
	}



	system("pause");
	return 0;
}