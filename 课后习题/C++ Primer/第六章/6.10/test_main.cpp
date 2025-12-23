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



void chenge(int* p1, int* p2);




int main()
{
	int a = 2, b = 20;

	int* pa = &a;
	int* pb = &b;
	cout << "交换前 a = " << a << "\tb = " << b << endl;


	chenge(pa, pb);

	cout << "交换后 a = " << a << "\tb = " << b << endl;
	//cout << a << " " << b << endl;




	system("pause");
	return 0;
}


void chenge(int* p1, int* p2)
{
	int temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}

