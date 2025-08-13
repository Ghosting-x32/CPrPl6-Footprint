#include <iostream>
#include<initializer_list>

using namespace std;

template<typename T>
T average_list(const initializer_list<T>& av);


int main()
{
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;

	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;

	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;



	system("pause");
	return 0;
}

template<typename T>
T average_list(const initializer_list<T>& av)//initializer_list也相当于一个容器，所以能当做容器来使用
{
	double tot = 0.0;
	int n = av.size();
	double ave = 0.0;
	if (n > 0)
	{
		for (auto pt = av.begin(); pt != av.end(); pt++)
		{
			tot += *pt;

		}
		ave = tot / n;

	}
	return ave;

}
