#include"Wine.h"


Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	:m_Name(l), m_YrBot(ArrayInt(yr, y),ArrayInt(bot,y))	
	//ArrayInt(yr, y)和ArrayInt(bot,y)其实就是两个匿名对象
	//有对象名的时候是这样初始化：valarray<int>v4(yr, y);---构造函数接受一个数组和需拷贝数组大小的值
{
	this->m_YrNum = y;

}


Wine::Wine(const char* l, int y)
	:m_Name(l), m_YrBot(ArrayInt(y), ArrayInt(y))
	//ArrayInt(yr, y)和ArrayInt(bot,y)其实就是两个匿名对象
	//有对象名的时候是这样初始化：valarray<int>v4(y);---构造函数只接受一个数组大小的值
{
	this->m_YrNum = y;

}


void Wine::GetBottles()
{
	cout << this->m_Name << " data for " << this->m_YrNum << " year(s)\n";
	for (int i = 0; i < this->m_YrNum; i++)
	{
		
		cout << "Enter year: ";
		while (!(cin >> (this->m_YrBot.first()[i])))
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

		cout << "Enter bottles for that year: ";

		while (!(cin >> (this->m_YrBot.second()[i])))
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

}


void Wine::Show()
{
	cout << "Wine: " << this->m_Name << endl;
	cout << "\tYear\tBottles\n";
	for (int i = 0; i < this->m_YrNum; i++)
	{
		cout << "\t" << this->m_YrBot.first()[i] << "\t" << this->m_YrBot.second()[i] << endl;

	}

}


string& Wine::Label()
{
	return this->m_Name;

}


int Wine::sum()
{
	return this->m_YrBot.second().sum();

}