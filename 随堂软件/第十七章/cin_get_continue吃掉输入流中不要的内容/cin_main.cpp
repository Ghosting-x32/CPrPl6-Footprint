#include<iostream>

using namespace std;

const int SLEN = 10;

inline void eatline()//使用内联函数吃掉输入流中不需要的字符
{
	while (cin.get() != '\n')
	{
		continue;
	}

}



int main()
{
	char name[SLEN];
	char title[SLEN];

	cout << "Enter your name: ";
	cin.get(name, SLEN);
	if (cin.peek() != '\n')
	{
		cout << "Sorry, we only have enough room for "
			<< name << endl;
	}

	eatline();

	cout << "Dear " << name << ", enter your title: \n";
	cin.get(title, SLEN);
	if (cin.peek() != '\n')
	{
		cout << "we were forced to truncate your title.\n";


	}
	eatline();

	cout << " Name: " << name
		<< "\nTitle: " << title << endl;



	system("pause");
	return 0;
}