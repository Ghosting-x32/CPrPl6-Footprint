#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	vector<string> text(3);
	text.push_back("Hello World.");
	text.push_back("aaa bbb");
	text.push_back("ccc.");
	text.push_back("ddd");
	text.push_back("fff");
	text.push_back("");
	text.push_back("eee.");

	for (const auto& s : text)
	{
		cout << s;
		if (s.empty() || s[s.size() - 1] == '.')
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}






	system("pause");
	return 0;
}