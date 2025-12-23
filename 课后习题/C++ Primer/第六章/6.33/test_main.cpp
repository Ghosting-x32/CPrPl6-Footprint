#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>






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
using std::initializer_list;



void show_vector(const vector<int>& vi1);//自己写的版本
void print(vector<int> vInt, decltype(vInt.size()) index);//答案的版本


int main()
{
	vector<int> v1(10, 55);

	for (auto& c : v1)
	{
		cout << c << " ";
	}

	cout << endl;

	for (decltype(v1.size()) i = 0; i < 10; ++i)
	{
		v1[i] = i + 3;
	}




	show_vector(v1);
	cout << endl;
	//show_vector(v1);//不能按预计的效果输出
	//cout << endl;

	print(v1, 0);
	cout << endl;
	print(v1, 0);
	cout << endl;


	system("pause");
	return 0;

}


void print(vector<int> vInt, decltype(vInt.size()) index)
{
	if (!vInt.empty() && index < vInt.size())
	{
		cout << vInt[index] << " ";
		print(vInt, ++index);
	}

	return;

}




void show_vector(const vector<int>& vi1)
{
	static decltype(vi1.size()) i = 0;//导致在main函数里只能调用一次，调用第二次时，i的值从上一个调用的vector的size开始递增

	if (i < vi1.size())
	{
		cout << vi1[i] << " ";
		++i;
		show_vector(vi1);
	}

	return;


}



