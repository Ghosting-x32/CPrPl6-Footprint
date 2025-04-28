#include"Worker.h"

Worker::Worker(const string& s, long n)
{
	this->fullname = s;
	this->id = n;

}


Worker::Worker()
{
	this->fullname = "no  one";
	this->id = 0L;

}


Worker::~Worker()
{


}


void Worker::Data()const
{
	cout << "Name: " << this->fullname << "\n";
	cout << "Employee ID: " << this->id << "\n";

}


void Worker::Get()
{
	cout << "Enter worker's name: ";
	getline(cin, this->fullname);
	cout << "Enter worker's ID: ";
	while (!(cin >> this->id))
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