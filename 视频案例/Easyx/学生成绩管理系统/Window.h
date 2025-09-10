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

	//����������������
	//�ж���û����Ϣ
	inline static bool hasMsg() 
	{
		return peekmessage(&m_msg, EX_MOUSE | EX_KEY);
	
	
	}
	//��ȡ��Ϣ
	inline static  ExMessage& getMsg() 
	{
		return m_msg;
	
	}


private:
	HWND m_handle;//���ھ��

	inline static ExMessage m_msg;//c++17֮��ֱ�Ӽ�inline

};

