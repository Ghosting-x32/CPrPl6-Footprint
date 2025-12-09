#include<iostream>
#include<string>
#include<cctype>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
		<< " separated by spaces. Hit ENTER when finished: "//应该是CTRL+Z结束输入（结束循环）
		<< endl;
	string result;
	string::size_type n;
	while (cin >> n)
	{
		if (n < hexdigits.size())
		{
			result += hexdigits[n];
		}
	}
	cout << "Your hex number is: " << result << endl;


	system("pause");
	return 0;
}