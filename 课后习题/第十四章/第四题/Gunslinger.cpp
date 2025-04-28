#include"Gunslinger.h"

Gunslinger::Gunslinger(int num, const string& xi, const string& mi)
	:Person(xi, mi)
{

	this->m_Numkh = num;

}



double Gunslinger::Draw()const
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis_real(0.0, 5.0);
	return dis_real(gen);

}



void Gunslinger::Show()const
{
	Person::Show();
	cout << "枪手抢上的刻痕数: " << this->m_Numkh << endl;
	cout << "枪手的拔枪时间: " << this->Draw() << " 秒" << endl;

}

const int& Gunslinger::viewkh()const
{
	return this->m_Numkh;

}


void Gunslinger::Set()
{
	Person::Set();
	cout << "请输入枪手抢上的刻痕数: ";
	while (!(cin >> this->m_Numkh))
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