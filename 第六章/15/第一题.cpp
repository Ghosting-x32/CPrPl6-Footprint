#include<iostream>
#include<cctype>
int main()
{
	using namespace std;
	cout << "请输入你的字符：" << endl;
	char ch;
	cin.get(ch);
	while (cin.get(ch) && ch != '@')
	{
		if (!isdigit(ch))
		{
			if (islower(ch))
			{
				ch = toupper(ch);
				cout << ch;
			}
			else
			{
				ch = tolower(ch);
				cout << ch;
			}
		}
	}



	cin.get();
	cin.get();
	return 0;
}
