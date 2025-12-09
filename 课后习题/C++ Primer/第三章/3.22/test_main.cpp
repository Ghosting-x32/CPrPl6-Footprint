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
	vector<string> text(10);
	string s("some string");
	text[0] = s;
	text[2] = "aaa bbb";
	text.push_back(s);

	cout << "text的元素个数是: " << text.size() << endl;
	cout << "text的各个元素分别是: " << endl;
	for (auto& c : text)
	{
		cout << c << "*" << endl;
	}

	cout << "直到遇到空字符串的元素停止输出，内容输出前先改为大写: " << endl;

	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
	{
		for (auto& c : *it)
		{
			c = toupper(c);
		}
		cout << *it << "*" << endl;
	}



	system("pause");
	return 0;
}