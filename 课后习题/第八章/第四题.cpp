#include<iostream>
#include<cstring>
using namespace std;
struct stringy
{
	char* str;
	int ct;
};
void set(stringy& a1, char ar1[]);
void show(const char ar[], int n = 1);
void show(const stringy a2, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	cout << endl;
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");








	system("pause");
	return 0;
}

void set(stringy& a1, char ar1[])
{
	char* pd = new char;
	pd = ar1;
	a1.str = pd;
}

void show(const char ar[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "数组内容是：" << ar << endl;
}

void show(const stringy a2, int n)
{
	for (int i = 0; i < n; i++)
		cout << "str: " << a2.str << endl;
}