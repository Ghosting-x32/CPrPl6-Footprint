#include"Singer.h"

const char* Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};


Singer::Singer()
	:Worker()
{
	this->voice = other;

}


Singer::Singer(const string& s, long n, int v)
	:Worker(s, n)
{
	this->voice = v;

}


Singer::Singer(const Worker& wk, int v)
	:Worker(wk)
{
	this->voice = v;

}


void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer' vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << this->pv[i] << " ";
		if (i % 4 == 3)
		{
			cout << endl;
		}

	}
	if (i % 4 != 0)
	{
		cout << endl;
	}

	while (true)
	{
		while (!(cin >> this->voice))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Incorrect input, please enter a number!" << endl;
		}

		if (this->voice < 0 || this->voice >= Vtypes)
		{
			cout << "Input error, please re-enter!" << endl;
			cout << "Please enter a value >= 0 and < " << Vtypes << endl;

		}
		else
		{
			break;

		}

	}
	while (cin.get() != '\n')
	{
		continue;
	}


}


void Singer::Show()const
{
	cout << "Category: singer\n";
	Worker::Show();
	cout << "Vocal range: " << this->pv[this->voice] << endl;

}