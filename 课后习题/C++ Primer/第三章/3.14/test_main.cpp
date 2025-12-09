#include<iostream>
#include<vector>
#include<string>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;

int main()
{
	vector<int> v1;
	int a = 0;

	cout << "请输入一组整数: ";
	while (cin >> a)
	{
		v1.push_back(a);
	}

	cout << "你输入的一组整数为: ";
	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}