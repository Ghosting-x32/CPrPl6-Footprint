#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void r1(const double& rx) { cout << rx << endl; }
void r2(double& rx) { cout << rx << endl; }
void r3(double&& rx) { cout << rx << endl; }


int main()
{
	double w = 10.0;
	r1(w);
	r1(w + 1);
	r1(up(w));
	r2(w);
	r2(w + 1);
	r2(up(w));
	r3(w);
	r3(w + 1);
	r3(up(w));
	return 0;
}


/*
r1(w)合法，形参rx 指向w。
r1(w+1)合法，形参rx 指向一个临时变量，这个变量被初始化为w+1。
r1(up(w))合法，形参rx 指向一个临时变量，这个变量被初始化为up(w)的返回值。
一般而言，将左值传递给const 左值引用参数时，参数将被初始化为左值。将右值传递给函数时，const
左值引用参数将指向右值的临时拷贝。




r2(w)合法，形参rx 指向w。
r2(w+1)非法，因为w+1 是一个右值。
r2(up(w))非法，因为up(w)的返回值是一个右值。
一般而言，将左值传递给非const 左值引用参数时，参数将被初始化为左值；但非const 左值形参不能
接受右值实参。




r3(w)非法，因为右值引用不能指向左值（如w）。
r3(w+1)合法，rx 指向表达式w+1 的临时拷贝。
r3(up(w))合法，rx 指向up(w)的临时返回值。



*/