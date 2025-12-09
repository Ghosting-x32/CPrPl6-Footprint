#include<iostream>
#include<string>
#include<cctype>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{


	string s("Hello World!!!");
	
	for (auto &c : s)//auto自动推断c为引用，依次绑定到对象s的每一个元素
	{
		c = toupper(c);//如果c是小写字母，输出对应的大写字母，否则原样输出
	}

	cout << s << endl;




	system("pause");
	return 0;
}