#pragma once
#include<iostream>
#include<string>

//#include"Remote.h"//编译器看到头文件要先构建头文件的类

using namespace std;
class Remote;

class Tv
{
public:
	friend class Remote;//a互为友元
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

	void set_m_zutai(Remote& rt);//d添加切换模式的方法


private:
	int state;//开or关
	int volume;//音量
	int maxchannel;
	int channel;//频道
	int mode;//有线电视or天线调节模式
	int input;//TV调谐orA/V输入（DVD）



};


class Remote
{
public:
	friend class Tv;//a互为友元

	enum { Cha, Hud };//b常规模式还是互动模式

	Remote(int m = Tv::TV, int zt = Cha);
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_chan(Tv& t, int c);
	void set_mode(Tv& t);
	void set_input(Tv& t);

	void viewzt();//c添加一个显示模式的方法
	//friend void set_m_zutai(Remote& rt);


private:

	int mode;
	int m_zutai;//b添加状态变量成员

};
