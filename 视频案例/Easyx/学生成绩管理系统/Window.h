#pragma once
#include<easyx.h>
#include<string>


class Window
{
public:
	Window(int w, int h, int flag);
	Window(int w, int h);

	void setWindowTitle(const std::string& title);

	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//按键操作和鼠标操作
	//判断有没有消息
	inline static bool hasMsg() 
	{
		return peekmessage(&m_msg, EX_MOUSE | EX_KEY);
	
	
	}
	//获取消息
	inline static  ExMessage& getMsg() 
	{
		return m_msg;
	
	}


private:
	HWND m_handle;//窗口句柄

	inline static ExMessage m_msg;//c++17之后直接加inline

};

