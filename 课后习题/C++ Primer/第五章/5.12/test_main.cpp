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
	unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;

	
	string str;
	cin >> str;
	for (auto c = str.begin(); c != str.end(); ++c)
	{

		if (*c == 'f')
		{
			switch (*(c + 1))
			{
			case 'f':
				++ffCnt;
				break;
			case 'l':
				++flCnt;
				break;
			case 'i':
				++fiCnt;
				break;
			}
		}



	}


	cout << "ff的数量: \t" << ffCnt << endl;
	cout << "fl的数量: \t" << flCnt << endl;
	cout << "fi的数量: \t" << fiCnt << endl;


	system("pause");
	return 0;
}