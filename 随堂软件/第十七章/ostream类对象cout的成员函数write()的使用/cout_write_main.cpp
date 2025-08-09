#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	const char* state1 = "Florida";
	const char* state2 = "Kansas";
	const char* state3 = "Euphoria";
	int len = strlen(state2);
	cout << "Increasing loop index:\n";
	int i;
	for (i = 1; i <= len; i++)
	{
		cout.write(state2, i);//warite(指向字符串的指针（地址）， 显示字符串的数目)
		cout << endl;

	}

	cout << "Decreasing loop index:\n";
	for (i = len; i > 0; i--)
	{
		cout.write(state2, i) << endl;//write()返回cout&，可以连续输出

	}

	cout << "Exceeding string length:\n";
	cout.write(state2, len + 5) << endl;//超出了state2,write还在继续输出state2后面内存中的未知内容

	cout << "Exceeding string length:\n";
	cout.write(state2, len - 7) << endl;//超出了state2,write还在继续输出state2前面内存中的未知内容



	system("pause");
	return 0;
}