﻿#include<iostream>
template<typename T>
void swapr(T& a, T& b);
struct job
{
	char name[40];
	double salary;
	int floor;
};

template<> void swapr<job>(job& j1, job& j2);
void show(job& j);


int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	swapr(i, j);
	cout << "Now i, j = " << i << ", " << j << ".\n";

	job sue = { "Susan Yaffe", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "Before job swapping:\n";
	show(sue);
	show(sidney);
	swapr(sue, sidney);
	cout << "After job swapping:\n";
	show(sue);
	show(sidney);
	system("pause");
	return 0;
}

template<typename T>
void swapr(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<> void swapr<job>(job& j1, job& j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void show(job& j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary
		<< " on floor " << j.floor << endl;
}