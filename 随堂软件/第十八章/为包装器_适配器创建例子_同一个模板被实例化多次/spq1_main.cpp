#include<iostream>
#include"Fp.h"
#include"Fq.h"


using namespace std;

double dub(double x);
double square(double x);



template <typename T, typename F>
T use_f(T v, F f);


int main()
{
	double y = 1.21;


	cout << "Function pointer dub:\n";
	cout << " " << use_f(y, dub) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f(y, square) << endl;

	cout << "Function object Fp:\n";
	cout << " " << use_f(y, Fp(5.0)) << endl;
	cout << "Function object Fq:\n";
	cout << " " << use_f(y, Fq(5.0)) << endl;

	cout << "Lambda expression 1:\n";
	cout << " " << use_f(y, [](double u) {return u * u; }) << endl;
	cout << "Lambda expression 2:\n";
	cout << " " << use_f(y, [](double u) {return u + u / 2.0; }) << endl;











	system("pause");
	return 0;
}


template <typename T, typename F>
T use_f(T v, F f)
{
	static int count = 0;
	count++;
	cout << "use_f count = " << count << ", &count = " << &count << endl;
	return f(v);

}


double dub(double x)
{
	return 2.0 * x;


}


double square(double x)
{
	return x * x;


}
