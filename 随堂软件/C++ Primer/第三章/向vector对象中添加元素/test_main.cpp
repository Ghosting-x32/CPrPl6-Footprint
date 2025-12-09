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
	vector<int> v2;

	for (int i = 0; i != 100; ++i)
	{
		v2.push_back(i);
	}

	for (auto& c : v2)
	{
		cout << c << " ";
	}

	cout << endl;

	string word;
	vector<string> text;

	while (cin >> word)
	{
		text.push_back(word);
	}

	for (auto& c : text)
	{
		cout << c << " ";
	}

	system("pause");
	return 0;
}