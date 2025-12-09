#include<iostream>
#include<vector>
#include<string>
#include<cctype>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;

int main()
{
	vector<string> v1;
	string str;

	cout << "请输入一组单词: " << endl;
	while (cin >> str)
	{
		v1.push_back(str);
	}

	cout << "你输入的一组单词分别是: " << endl;
	for (auto& c : v1)
	{
		cout << c << endl;

	}

	for (auto& c : v1)
	{
		for (auto& i : c)
		{
			i = toupper(i);
		}
	}

	cout << "转换为大写后的单词分别是: " << endl;
	for (auto& c : v1)
	{
		cout << c << endl;

	}


	system("pause");
	return 0;
}