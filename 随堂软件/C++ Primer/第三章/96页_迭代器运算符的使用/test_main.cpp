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
	string s("some string");
	if (s.begin() != s.end())
	{
		auto it = s.begin();
		*it = toupper(*it);
	}

	cout << s << endl;



	system("pause");
	return 0;
}