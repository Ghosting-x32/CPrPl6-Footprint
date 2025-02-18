#include<iostream>
#include"golf.h"
const int STKS = 4;

int main()
{
	using namespace std;
	Golf cssz[STKS];
	for (int i = 0; i < STKS && cssz[i].setgolf(); i++)
	{
		if (i < (STKS-1))
			cout << "next one!!\a" << endl;
	}
	for (int i = 0; i < STKS; i++)
	{
		cout << "第" << (i + 1) << "个类对象" << endl;
		cssz[i].Show();
		cout << endl << endl;
	}





	

	system("pause");
	return 0;
}
