#pragma once
#include<iostream>
#include<string>

//#include"Remote.h"//����������ͷ�ļ�Ҫ�ȹ���ͷ�ļ�����

class Remote;

using namespace std;




class Tv
{
public:
	friend void set_chan(Tv& t, int c);
	enum { Off, On };
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv(int s = Off, int mc = 125);
	void onoff();
	bool ison()const;
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode();
	void set_input();
	void settings();




private:
	int state;//��or��
	int volume;//����
	int maxchannel;
	int channel;//Ƶ��
	int mode;//���ߵ���or���ߵ���ģʽ
	int input;//TV��гorA/V���루DVD��



};
