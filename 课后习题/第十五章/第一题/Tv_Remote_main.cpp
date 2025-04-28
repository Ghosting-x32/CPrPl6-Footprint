#include<iostream>
#include<string>

#include"Tv.h"
#include"Remote.h"



using namespace std;

int main()
{

	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();

	Remote grey1;
	//��һ����Դ���
	cout << "========================" << endl;
	grey1.viewzt();
	s42.set_m_zutai(grey1);
	grey1.viewzt();
	cout << "========================" << endl;
	//��һ����Դ���

	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	Remote grey;
	//��һ����Դ���
	cout << "========================" << endl;
	grey.viewzt();
	s42.set_m_zutai(grey);
	grey.viewzt();
	cout << "========================" << endl;
	//��һ����Դ���

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();



	system("pause");
	return 0;
}