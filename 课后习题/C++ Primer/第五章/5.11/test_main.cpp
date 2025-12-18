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
	unsigned int kgCnt = 0, zbCnt = 0, hhCnt = 0;

	char ch = 'a';

	while (cin.get(ch))
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++kgCnt;
			break;
		case '\t':
			++zbCnt;
			break;
		case '\n':
			++hhCnt;
			break;

		}

	}

	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "空格的数量是: \t" << kgCnt << '\n'
		<< "制表符的数量是: \t" << zbCnt << '\n'
		<< "换行符的数量是: \t" << hhCnt << '\n';


	system("pause");
	return 0;
}