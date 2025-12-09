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
	for (char &c : str)
	{
		c = 'X';
	}
	cout << str << endl;


	system("pause");
	return 0;
}
//就本题而言，将循环控制变量的类型设为char 不会对程序运行结果造成影响，
//因为我们使用auto 自动推断字符串s 的元素类型，结果同样是char。