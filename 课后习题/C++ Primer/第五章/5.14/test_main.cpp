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
	vector<string> v1;
	vector<string> v2;
	vector<unsigned int> v3;
	vector<unsigned int> v4;

	string str;
	//string str1;


	unsigned int num = 1;
	//unsigned int num1 = 0;
	cout << "请输入一组单词:" << endl;
	while (cin >> str)
	{
		v1.push_back(str);
	}




	//for (decltype(v1.size()) i = 0; i < v1.size() - 1; ++i)//金典的多个连续重复的元素只输出一个案例
	//{
	//	if (v1[i] == v1[i + 1])
	//	{
	//		if (i == 0 || v1[i] != v1[i - 1])
	//		{
	//			cout << v1[i] << " ";
	//		}
	//		
	//	}

	//}

	//cout << "\n********************************************\n";




	for (decltype(v1.size()) i = 0; i < v1.size() - 1; ++i)
	{
		if (v1[i] == v1[i + 1])
		{

			while (i + num < v1.size() && v1[i] == v1[i + num])
			{
				++num;
			}

			v2.push_back(v1[i]);//储存连续出现过的单词
			v3.push_back(num);//储存对应连续出现过的单词的次数


			i += num - 1;

			//多个连续重复的元素只处理一个元素的案例----循环里面嵌套一个循环单独处理当前连续重复的元素，然后调整步长，跳过已经处理过的元素


		}
		else
		{
			num = 1;
		}


	}

	if (v2.size() == 0)
	{
		cout << "所有单词都没有连续出现过!" << endl;
	}
	else
	{
		unsigned int nummax = 0;//储存连续出现最多的次数
	
		for (decltype(v3.size()) i = 0; i < v3.size(); ++i)
		{
			if (nummax < v3[i])
			{
				nummax = v3[i];
			}
		}

		for (decltype(v3.size()) i = 0; i < v3.size(); ++i)
		{
			if (nummax == v3[i])
			{
				v4.push_back(i);
			}
		}

		for (decltype(v4.size()) i = 0; i < v4.size(); ++i)
		{
			cout << v2[v4[i]] << " ";
		}

		if (v4.size() == 1)
		{
			cout << "连续出现的次数最多,最多的连续出现次数为: " << nummax << endl;
		}
		else
		{
			cout << "连续出现的次数相同且最多,最多的连续出现次数均为: " << nummax << endl;
		}
		
	}



	system("pause");
	return 0;
}