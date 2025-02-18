#include<iostream>
#include"golf.h"
using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	cout << "please enter fullname : ";
	cin.getline(g.fullname, Len);
	if (strlen(g.fullname) == 0)
		return 0;
	else
	{
		cout << "please enter handicap : ";
		cin >> g.handicap;
		cin.get();
		return 1;
	}
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	cout << "fullname : " << g.fullname << ", handicap : " << g.handicap << endl;
}