#include"Waiter.h"

Waiter::Waiter()
	:Worker()
{
	this->panache = 0;

}


Waiter::Waiter(const string& s, long n, int p)
	:Worker(s, n)
{
	this->panache = p;

}


Waiter::Waiter(const Worker& wk, int p)
	:Worker(wk)
{
	this->panache = p;

}


void Waiter::Set()
{
	Worker::Get();
	this->Get();
	
}


void Waiter::Show()const
{
	cout << "Category: waiter\n";
	Worker::Data();
	this->Data();

}

void Waiter::Data()const
{

	cout << "Panache rating: " << this->panache << endl;

}


void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	while (!(cin >> this->panache))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Incorrect input, please enter a number!" << endl;
	}
	while (cin.get() != '\n')
	{
		continue;
	}

}