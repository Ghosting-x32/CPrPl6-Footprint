#pragma once
#include<iostream>
#include<string>

//#include"Remote.h"//编译器看到头文件要先构建头文件的类

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
	int state;//开or关
	int volume;//音量
	int maxchannel;
	int channel;//频道
	int mode;//有线电视or天线调节模式
	int input;//TV调谐orA/V输入（DVD）



};
