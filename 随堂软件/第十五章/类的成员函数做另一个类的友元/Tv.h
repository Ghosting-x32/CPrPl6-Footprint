#pragma once
#include<iostream>
#include<string>

//#include"Remote.h"//����������ͷ�ļ�Ҫ�ȹ���ͷ�ļ�����

class Tv;//��ǰ����

using namespace std;

class Remote
{
public:
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Remote(int m = TV);
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_chan(Tv& t, int c);
	void set_mode(Tv& t);
	void set_input(Tv& t);



private:

	int mode;


};




class Tv
{
public:
	friend void Remote::set_chan(Tv& t, int c);//����Ҫ�ñ������ȿ�����������������෽��
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
