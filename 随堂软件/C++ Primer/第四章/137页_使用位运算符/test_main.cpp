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
	unsigned long quizl = 0;

	quizl |= 1UL << 27;//27位设置为1

	quizl &= ~(1UL << 27);//27位设置为0
	//quizl = quizl & ~(1UL << 27);等效于这个

	bool status = quizl & 1UL << 27;

	if (status)
	{
		cout << "27位上是1" << endl;
	}
	else
	{
		cout << "27位上是0" << endl;
	}


	system("pause");
	return 0;
}