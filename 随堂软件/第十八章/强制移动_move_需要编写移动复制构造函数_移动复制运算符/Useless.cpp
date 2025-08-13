#include"Useless.h"

int Useless::ct = 0;
Useless::Useless()
{
	this->ct = ++ct;
	this->n = 0;
	this->pc = nullptr;

	//cout << "default constructor called; number of objects: " << this->ct << endl;
	//this->ShowObject();

}


Useless::Useless(int k)
	:n(k)
{
	++ct;
	//cout << "int constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	//ShowObject();

}


Useless::Useless(int k, char ch)
	:n(k)
{
	++ct;
	//cout << "int, char constructor called: number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
	{
		pc[i] = ch;

	}
	//ShowObject();


}


Useless::Useless(const Useless& f)
	:n(f.n)
{
	++ct;
	//cout << "copy const called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
	{
		pc[i] = f.pc[i];
	}
	//ShowObject();



}


Useless::Useless(Useless&& f)
	:n(f.n)
{
	++ct;
	//cout << "move constructor called; number of objects: " << ct << endl;

	//右值引用为移动语义服务，移动语义即转让所有权
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;

	//ShowObject();



}


Useless::~Useless()
{
	--ct;
	//cout << "destructor called: objects left: " << ct << endl;
	//cout << "deleted object:\n";
	//ShowObject();
	delete[] pc;


}


Useless Useless::operator+(const Useless& f)const
{
	//cout << "Entering operator+()\n";
	Useless temp = Useless(n + f.n);//走explicit Useless(int k);构造函数
	//留下疑问：为什么不走Useless(Useless&& f);构造函数

	for (int i = 0; i < n; i++)
	{
		temp.pc[i] = pc[i];
	}
	for (int i = n; i < temp.n; i++)
	{
		temp.pc[i] = f.pc[i - n];
	}
	//cout << "temp object:\n";
	//cout << "Leaving operator+()\n";


	return temp;
}


void Useless::ShowData()const
{
	if (n == 0)
	{
		cout << "(object empty)";

	}
	else
	{
		for (int i = 0; i < n; i++)
		{

			cout << pc[i];
		}


	}
	cout << endl;
}


void Useless::ShowObject()const
{
	cout << "number of elements: " << n;
	cout << " Data address: " << (void*)pc << endl;



}


Useless& Useless::operator=(const Useless& f)
{
	cout << "copy assignment operator called:\n";

	if (this == &f)
	{
		return *this;

	}
	delete[] pc;

	n = f.n;
	pc = new char[n];
	for (int i = 0; i < n; i++)
	{
		pc[i] = f.pc[i];

	}

	return *this;


}


Useless& Useless::operator=(Useless&& f)
{
	cout << "move assignment operator called:\n";
	if (this == &f)
	{
		return *this;

	}
	delete[] pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;

	return *this;



}