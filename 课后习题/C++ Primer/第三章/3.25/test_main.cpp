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

	vector<unsigned> scores(11, 0);

	unsigned grade = 0;


	while (cin >> grade)
	{
		if (grade <= 100)
		{			
			auto it = scores.begin() + (grade / 10);

			++(*it);

		}
	}


	//while (cin >> grade)
	//{
	//	if (grade <= 100)
	//	{
	//		++scores[grade / 10];
	//	}


	//}

	for (auto i : scores)
	{
		cout << i << " ";
	}
	cout << endl;






	system("pause");
	return 0;
}