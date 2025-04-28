#include"SingingWaiter.h"

SingingWaiter::SingingWaiter()
	:Worker(), Waiter(), Singer()
{



}


SingingWaiter::SingingWaiter(const string& s, long n, int p, int v)
	:Worker(s, n), Waiter(s, n, p), Singer(s, n, v)
{


}


SingingWaiter::SingingWaiter(const Worker& wk, int p, int v)
	:Worker(wk), Waiter(wk, p), Singer(wk, v)
{


}


SingingWaiter::SingingWaiter(const Singer& wt, int p)
	:Worker(wt), Waiter(wt, p), Singer(wt)
{


}


SingingWaiter::SingingWaiter(const Waiter& wt, int v)
	:Worker(wt), Waiter(wt), Singer(wt, v)
{


}


void SingingWaiter::Set()
{
	Worker::Get();
	this->Get();

}


void SingingWaiter::Show()const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	this->Data();

}

void SingingWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}


void SingingWaiter::Get()
{
	Singer::Get();
	Waiter::Get();

}