#include<iostream>
#include"list.h"

List::List()
{
	top = 0;
}

List::~List()
{
}

bool List::sfkong()const
{
	if (top == 0 || top < 0)
		return true;
	else
		return false;
}

bool List::sfman()const
{
	if (top == MZ || top > MZ)
		return true;
	else
		return false;
}

bool List::tianj(const Item& n)
{
	if (top < MZ)
	{
		darunf[top++] = n;
		std::cout << "»¹Ê£Óà " << MZ - top << " ¸ö´¢´æ¿Õ¼ä£¡" << std::endl;
		return true;
	}
	else
		return false;
}

void List::visit(void (*pf)(Item&))
{
	for (int i = 0; i < top; i++)
		pf(darunf[i]);
}