#include<iostream>

const int Limit = 225;

using namespace std;

int main()
{
	char input[Limit];

	cout << "Enter a string for getline() processing:\n";
	cin.getline(input, Limit, '#');//(char*, 最大数目字符, 分界符)----到达最大数目字符停止读取，到达分界符停止读取，分界符从输入流中被丢掉
	cout << "Herr is your input: \n";
	cout << input << "\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout << "The next input character ia " << ch << endl;

	if (ch != '\n')
	{
		cin.ignore(Limit, '\n');//丢掉输入流中Limit个字符，或者丢掉输入流'\n'之前的所有字符


	}

	cout << "Enter a string for get() processing:\n";
	cin.get(input, Limit, '#');//(char*, 最大数目字符, 分界符)----到达最大数目字符停止读取，到达分界符停止读取，分界符留在输入流中
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 2\n";

	cin.get(ch);
	cout << "The nex input character is " << ch << endl;




	system("pause");
	return 0;
}