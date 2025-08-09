#include<iostream>


using namespace std;

int main()
{
	char ch;

	while (cin.get(ch))
	{
		if (ch != '#')
		{
			cout << ch;

		}
		else
		{
			cin.putback(ch);//把上一个读取的字符放回输入流（把上一个读取的字符读回去）
			break;

		}


	}

	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		exit(0);

	}

	while (cin.peek() != '#')//查看输入流中的下一个字符
	{
		cin.get(ch);
		cout << ch;

	}

	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";


	}
	else
	{
		cout << "End of file reached.\n";

	}




	system("pause");
	return 0;
}