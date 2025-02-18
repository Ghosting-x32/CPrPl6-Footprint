#include<iostream>
#include"golf.h"

Golf::Golf()
{
	fullname = "no fullname";
	handicap = 0;
}

Golf::Golf(const std::string& ln, const int& pn)
{
	fullname = ln;
	handicap = pn;
}

Golf::~Golf()
{
}

void Golf::Show()const
{
	std::cout << "fullname: " << fullname << std::endl;
	std::cout << "handicp: " << handicap << std::endl;
}

int Golf::setgolf()
{
	std::string fn;
	int hp;
	std::cout << "ÇëÊäÈëfullname: ";
	getline(std::cin, fn);
	if (fn == "")
		return 0;
	else
	{
		std::cout << "ÇëÊäÈëhandicap: ";
		std::cin >> hp;
		std::cin.get();
		Golf lins = Golf(fn, hp);
		*this = lins;
		return 1;
	}
}

void Golf::handicap_s(int hc)
{
	handicap = hc;
}