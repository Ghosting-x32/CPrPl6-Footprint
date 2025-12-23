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



void exchange( int*& p1, int*& p2);




int main()
{
	
	int a1 = 20;
	int a2 = 100;

	int* pp1 = &a1;
	int* pp2 = &a2;

	cout << "交换前pp1是: " << pp1 << endl;
	cout << "交换前pp1指向的值是: " << *pp1 << endl;
	cout << "交换前pp2是: " << pp2 << endl;
	cout << "交换前pp2指向的值是: " << *pp2 << endl;
	cout << "***************************************" << endl;
	exchange(pp1, pp2);


	cout << "交换后pp1是: " << pp1 << endl;
	cout << "交换前pp1指向的值是: " << *pp1 << endl;
	cout << "交换后pp2是: " << pp2 << endl;
	cout << "交换前pp2指向的值是: " << *pp2 << endl;





	system("pause");
	return 0;
}


void exchange(int*& p1, int*& p2)
{
	int* temp = nullptr;

	temp = p1;
	p1 = p2;
	p2 = temp;

	
}
