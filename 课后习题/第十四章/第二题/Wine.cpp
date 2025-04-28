#include"Wine.h"


Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	:string(l), PairArray(ArrayInt(yr, y),ArrayInt(bot,y))
	//ArrayInt(yr, y)��ArrayInt(bot,y)��ʵ����������������
	//�ж�������ʱ����������ʼ����valarray<int>v4(yr, y);---���캯������һ��������追�������С��ֵ
{
	this->m_YrNum = y;

}


Wine::Wine(const char* l, int y)
	:string(l), PairArray(ArrayInt(y), ArrayInt(y))
	//ArrayInt(yr, y)��ArrayInt(bot,y)��ʵ����������������
	//�ж�������ʱ����������ʼ����valarray<int>v4(y);---���캯��ֻ����һ�������С��ֵ
{
	this->m_YrNum = y;

}


void Wine::GetBottles()
{
	cout << (const string&)(*this) << " data for " << this->m_YrNum << " year(s)\n";
	for (int i = 0; i < this->m_YrNum; i++)
	{
		
		cout << "Enter year: ";
		while (!(cin >> (PairArray::first()[i])))
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

		while (!(cin >> (PairArray::second()[i])))
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
	//cout << "Wine: " << this->m_Name << endl;
	cout << "Wine: " << (const string&)(*this) << endl;
	cout << "\tYear\tBottles\n";
	for (int i = 0; i < this->m_YrNum; i++)
	{
		//cout << "\t" << this->m_YrBot.first()[i] << "\t" << this->m_YrBot.second()[i] << endl;
		cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << endl;
	}

}


string& Wine::Label()
{
	//return this->m_Name;
	return (string&)*this;

}


int Wine::sum()
{
	//return this->m_YrBot.second().sum();
	return PairArray::second().sum();

}