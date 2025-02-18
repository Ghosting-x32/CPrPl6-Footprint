#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
T maxn(T ar[], int n);

template <> const char* maxn(const char* pn[], int n);





int main()
{
	int ar1[6] = { 1,2,3,4,5,6 };
	double ar2[4] = { 2.3,3.3,4.3,5.3 };
	const char* pn1[5] =
	{
		"testing",
		"haoyigecsx",
		"jjjhajjahjahja",
		"hhhjhahjhjhjhjergggg",
		"yyyyyyyyyyyyyyyyyyyy"
	};
	cout << maxn(ar1, 6) << endl;
	cout << maxn(ar2, 4) << endl;

	cout << maxn(pn1, 5) << endl;





	system("pause");
	return 0;
}

template <typename T>
T maxn(T ar[], int n)
{
	T temp = ar[0];
	for (int i = 0; i < n; i++)
		temp = temp > ar[i + 1] ? temp : ar[i + 1];
	return temp;
}

template <> const char* maxn(const char* pn[], int n)
{
	int j = 0;
	unsigned int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < strlen(pn[i]))
		{
			max = strlen(pn[i]);
			j = i;
		}
	}
	return pn[j];
}