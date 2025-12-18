#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;




int main()
{
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch = 'a';
	unsigned int vowelCnt = 0;
	unsigned int otherCnt = 0;

	while (cin >> ch)
	{
		switch(ch)
		{
			case 'a':			
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++vowelCnt;
				break;
			default:
				++otherCnt;
				break;

		}
			
	}

	cout << "Number of vowel a、e、i、o、u(总数): \t" << vowelCnt << '\n';
	cout << "不是元音字母的字符出现次数: \t" << otherCnt << '\n';
		




	system("pause");
	return 0;
}