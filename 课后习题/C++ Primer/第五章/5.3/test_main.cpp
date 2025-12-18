#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>

 






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;







int main()
{

	/*
	原文的while 循环使用了块，其形式是：
while ( val <= 10 )
{
sum += val;
++val;
}
利用逗号运算符改写之后的形式如下所示：
while ( val <= 10 )
sum += val, ++val;
很明显，改写之后的代码不够清晰，可读性降低了。
	
	
	*/
	int sum = 0, val = 1;

	//while (val <= 10)
	//{
	//	sum += val;
	//	++val;
	//}


	while (val <= 10)
		sum += val, ++val;
	
	

	cout << "Sum of 1 to 10 inclusive is " << sum << endl;



	system("pause");
	return 0;
}