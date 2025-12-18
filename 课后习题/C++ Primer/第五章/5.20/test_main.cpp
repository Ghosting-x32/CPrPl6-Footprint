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
	string str1, str2;
	cout << "请输入一组单词:" << endl;
	while (cin >> str1)
	{
		if (str2.size() == 0)
		{
			str2 = str1;
		}
		else
		{
			if (str1 == str2)
			{
				cout << "单词 " << str1 << " 连续重复出现" << endl;
				break;
			}
			else
			{
				str2 = str1;
			}
		}

		

	}

	if (!cin)
	{
		cout << "所有单词都没有连续重复出现!" << endl;
	}



	system("pause");
	return 0;
}