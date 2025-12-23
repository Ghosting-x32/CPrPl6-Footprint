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




size_t count_calls();


int main()
{
	
	for (size_t i = 0; i != 10; ++i)
	{
		cout << count_calls() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}



size_t count_calls()
{
	static size_t ctr = 0;


	return ++ctr;
}