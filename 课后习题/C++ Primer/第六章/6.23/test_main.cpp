#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;



void print1(const int* p);
void print2(const int* p, const int sz);
void print3(const int* p1, const int* p2);




int main()
{
	int i = 0, j[2] = { 0, 1 };
	
	print1(&i);
	print1(j);

	print2(&i, 1);
	print2(j, sizeof(j) / sizeof(j[0]));


	auto b = begin(j);
	auto e = end(j);
	print3(b, e);






	system("pause");
	return 0;
}


void print1(const int* p)
{
	cout << *p << endl;


}


void print2(const int* p, const int sz)
{
	int i = 0;
	while (i != sz)
	{
		cout << *p++ << " ";
		++i;
	}
	cout << endl;

}


void print3(const int* p1, const int* p2)
{
	for (auto q = p1; q != p2; ++q)
	{
		cout << *q << " ";
	}
	cout << endl;

}

