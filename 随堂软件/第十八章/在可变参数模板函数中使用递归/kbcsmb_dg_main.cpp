#include<iostream>
#include<string>

using namespace std;

void show_list3();

template<typename T, typename... Args>
void show_list3(T value, Args... args);




int main()
{
	int n = 14;
	double x = 2.71828;
	string mr = "Mr. String objects!";
	show_list3(n, x);
	show_list3(x * x, '!', 7, mr);


	cout << endl;






	system("pause");
	return 0;
}


void show_list3()
{

}


template<typename T, typename... Args>
void show_list3(T value, Args... args)
{
	cout << value << ",";
	show_list3(args...);




}