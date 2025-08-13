#include <iostream>
#include<algorithm>

using namespace std;

template<typename T>
void show2(double x, T fp);


int main()
{

	show2(18.0, [](double x) {return 1.8 * x + 32; });

	system("pause");
	return 0;
}

template<typename T>
void show2(double x, T fp)
{
	cout << x << " -> " << fp(x) << "\n";

}

