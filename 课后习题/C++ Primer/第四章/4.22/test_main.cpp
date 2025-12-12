#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	string finalgrade;
	int grade = 0;
	cin >> grade;


	//°æ±¾1
	//finalgrade = grade > 90 ? "high pass" : grade > 75 ? "pass" : grade > 60 ? "low pass" : "fail";

	//cout << finalgrade << endl;


	//°æ±¾2
	if (grade >= 60)
	{

		finalgrade = grade > 90 ? "high pass" : grade > 75 ? "pass" : "low pass";

	}
	else
	{
		finalgrade = "fail";
	}

	cout << finalgrade << endl;





	system("pause");
	return 0;
}