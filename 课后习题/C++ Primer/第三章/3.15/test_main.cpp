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
	vector<string> v1;
	string a;

	cout << "请输入一组字符串: ";
	while (cin >> a)
	{
		v1.push_back(a);
	}

	cout << "你输入的一组字符串为: ";
	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}