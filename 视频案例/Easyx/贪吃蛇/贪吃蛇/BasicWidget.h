#pragma once
#include<easyx.h>
#include<iostream>





class BasicWidget
{
public:
	BasicWidget(int x, int y,int w, int h);
	virtual ~BasicWidget();

	int width();
	int heigh();
	void setFixedSize(int w, int h);

	bool isin();//�ж�����Ƿ��ڵ�ǰ��ť����
	bool isClicked();//�ж�����Ƿ����˰�ť

	int x();
	int y();
	void move(int x, int y);

	virtual void show() = 0;
	virtual void event();
	void getmsg(ExMessage& msg);


	void setBackgroundColor(COLORREF& color);
	void setHoverColor(COLORREF& color);




protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	ExMessage m_msg;



	COLORREF cur_c = LIGHTGRAY;
	COLORREF normal_c = LIGHTGRAY;
	COLORREF hover_c = RGB(255, 0, 200);


};

