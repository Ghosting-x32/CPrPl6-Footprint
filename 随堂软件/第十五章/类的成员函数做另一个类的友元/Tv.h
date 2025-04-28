#pragma once
#include<iostream>
#include<string>

//#include"Remote.h"//编译器看到头文件要先构建头文件的类

class Tv;//向前声明

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
	friend void Remote::set_chan(Tv& t, int c);//必须要让编译器先看到有这个类和有这个类方法
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
