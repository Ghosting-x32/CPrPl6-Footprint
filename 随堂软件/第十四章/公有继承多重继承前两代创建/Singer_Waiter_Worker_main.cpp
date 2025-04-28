#include<iostream>
#include<string>

#include"Singer.h"
#include"Waiter.h"
#include"Worker.h"

using namespace std;

const int LIM = 4;

int main()
{
	Waiter bob("Bob", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);

	Waiter w_temp;
	Singer s_temp;

	Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; i++)
	{
		pw[i]->Set();
	}

	for (i = 0; i < LIM; i++)
	{

		pw[i]->Show();
		cout << endl;
	}


	system("pause");
	return 0;
}