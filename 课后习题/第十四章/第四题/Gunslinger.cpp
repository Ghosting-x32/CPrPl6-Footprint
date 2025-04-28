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
	cout << "ǹ�����ϵĿ̺���: " << this->m_Numkh << endl;
	cout << "ǹ�ֵİ�ǹʱ��: " << this->Draw() << " ��" << endl;

}

const int& Gunslinger::viewkh()const
{
	return this->m_Numkh;

}


void Gunslinger::Set()
{
	Person::Set();
	cout << "������ǹ�����ϵĿ̺���: ";
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