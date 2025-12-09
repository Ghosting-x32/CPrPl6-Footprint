#include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//1.将输入的字符串连接在一起
	string str;
	string str1;
	string str2;

	while (cin >> str1)
	{
		str += str1;

	}

	cout << str << endl;


	//2.将输入的字符串用空格分隔开连在一起

	cin.clear();//CTRL+Z模拟文件尾结束循环结束输入（cin输入失败）导致cin重置位，需要再次重置位（恢复cin输入）

	while (cin >> str1)
	{
		string temp = str1 + " ";//导致最后有个空格
		str2 += temp;//str2 = str2 + " " + str1;---导致开头有个空格

	}

	//cout << str2.size() << "******" << endl;
	//str2.pop_back();
	//cout << str2.size() << "******" << endl;
	cout << str2;
	system("pause");
	//cout << endl;

	cout << str2.size() << "******" << endl;
	str2.pop_back();//解决导致最后有个空格的问题（把最后一个元素弹出）
	cout << str2.size() << "******" << endl;
	cout << str2;

	





	system("pause");
	return 0;
}