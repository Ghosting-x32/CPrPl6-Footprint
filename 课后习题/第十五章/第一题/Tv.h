#pragma once
#include<iostream>
#include<string>

//#include"Remote.h"//����������ͷ�ļ�Ҫ�ȹ���ͷ�ļ�����

using namespace std;
class Remote;

class Tv
{
public:
	friend class Remote;//a��Ϊ��Ԫ
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

	void set_m_zutai(Remote& rt);//d����л�ģʽ�ķ���


private:
	int state;//��or��
	int volume;//����
	int maxchannel;
	int channel;//Ƶ��
	int mode;//���ߵ���or���ߵ���ģʽ
	int input;//TV��гorA/V���루DVD��



};


class Remote
{
public:
	friend class Tv;//a��Ϊ��Ԫ

	enum { Cha, Hud };//b����ģʽ���ǻ���ģʽ

	Remote(int m = Tv::TV, int zt = Cha);
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_chan(Tv& t, int c);
	void set_mode(Tv& t);
	void set_input(Tv& t);

	void viewzt();//c���һ����ʾģʽ�ķ���
	//friend void set_m_zutai(Remote& rt);


private:

	int mode;
	int m_zutai;//b���״̬������Ա

};
