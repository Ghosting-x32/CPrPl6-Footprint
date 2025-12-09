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
	vector<int> v1;
	int a = 0;
	int b = 0;

	cout << "请输入一组整数: " << endl;
	while (cin >> a)
	{
		v1.push_back(a);
	}

	cout << "你输入的一组整数是: " << endl;
	for (auto& c : v1)
	{
		cout << c << " ";

	}
	cout << endl;

	cout << "每对相邻的整数的和分别是: " << endl;
	for (decltype(v1.size()) i = 0; i < v1.size() - 1; i++)
	{
		b = v1[i] + v1[i + 1];
		cout << b << " ";

	}
	
	cout << endl;





	system("pause");
	return 0;
}