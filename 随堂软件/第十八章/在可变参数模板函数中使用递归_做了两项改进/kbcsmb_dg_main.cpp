#include<iostream>
#include<string>

using namespace std;

void show_list3();

template<typename T>
void show_list3(const T& value);

template<typename T, typename... Args>
void show_list3(const T& value, const Args&... args);//1.按引用传递值，提高程序效率




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
void show_list3(const T& value, const Args&... args)
{
	cout << value << ",";
	show_list3(args...);




}


template<typename T>
void show_list3(const T& value)
{

	cout << value << '\n';//2.递归到只有一项时，将走这个函数，最后打印换行符，由于没有调用（递归）自己，递归也将结束

}