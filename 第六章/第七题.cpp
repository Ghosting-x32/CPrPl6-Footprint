#include<iostream>
#include<cctype>
#include<string>
int main()
{
	using namespace std;
	cout << "Enter words (q to quit): \n";
	string ch;
	int yuy = 0;
	int fuy = 0;
	int qt = 0;
	int i = 0;
	cin >> ch;
	while (ch != "q")
	{

		if (isalpha(ch[0]))
		{
			if (ch[0] == 'a' || ch[0] == 'e' || ch[0] == 'i' || ch[0] == 'o' || ch[0] == 'u')
			{
				++yuy;
			}
			else
			{
				++fuy;
			}
		}
		else
			++qt;
		cin >> ch;
	}
	cout << yuy << " words beginning with vowels" << endl;
	cout << fuy << " words beginning with consonants\n";
	cout << qt << " others" << endl;


	system("pause");
	return 0;
}


