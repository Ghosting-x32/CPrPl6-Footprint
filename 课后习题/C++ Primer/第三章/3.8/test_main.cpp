#include<iostream>
#include<string>
#include<cctype>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str("Hello World!!!");

	cout << str << endl;



	//for (auto &c : str)//方法1
	//{
	//	c = 'X';
	//}

	//decltype(str.size()) n = 0;//方法2
	//while (n != str.size())
	//{
	//	str[n] = 'X';
	//	++n;

	//}

	for (decltype(str.size()) i = 0; i != str.size(); ++i)//方法3
	{
		str[i] = 'X';

	}


	cout << str << endl;


	//在本例中，我们希望处理字符串中的每一个字符，且无须在意字符的处理顺序，
	//因此与传统的while 循环和for 循环相比，使用范围for 循环更简洁直观。





	system("pause");
	return 0;
}