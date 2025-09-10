#pragma once
#include<easyx.h>
#include"Window.h"





class BasicWidget
{
public:
	BasicWidget(int x, int y,int w, int h);
	virtual ~BasicWidget();

	int width();
	int heigh();
	void setFixedSize(int w, int h);

	bool isin();//判断鼠标是否在当前按钮上面
	bool isClicked();//判断鼠标是否点击了按钮

	int x();
	int y();
	void move(int x, int y);

	virtual void show() = 0;
	virtual void event();


	void setBackgroundColor(COLORREF& color);
	void setHoverColor(COLORREF& color);




protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;



	COLORREF cur_c = RGB(152, 255, 185);
	COLORREF normal_c = RGB(152, 255, 185);
	COLORREF hover_c = RED;


};

