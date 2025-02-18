#include<iostream>
#include"golf.h"
using namespace std;

int main()
{
	golf ann, andy;
	golf arrGolf[3];
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);

	if (setgolf(andy) == 1)
		showgolf(andy);
	handicap(andy, 20);
	showgolf(andy);

	int i = 0;
	while (i < 3 && setgolf(arrGolf[i]))
	{
		showgolf(arrGolf[i]);
		i++;
		if (i < 3)
			cout << "next one: " << endl;
	}

	system("pause");
	return 0;
}
