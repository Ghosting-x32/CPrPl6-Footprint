#include "Window.h"


//ExMessage Window::m_msg;//c++17֮ǰ������


Window::Window(int w, int h, int flag)
{
	this->m_handle = initgraph(w, h, flag);
	setbkmode(TRANSPARENT);
	//Ҳ������GetHWnd()----��ȡ���ھ��
	//initgraph(w, h, flag);
	//m_handle = GetHWnd();

}


Window::Window(int w, int h)
{
	this->m_handle = initgraph(w, h);
	setbkmode(TRANSPARENT);

}

void Window::setWindowTitle(const std::string& title)
{

	SetWindowText(this->m_handle, title.c_str());//ʹ��Windows API�޸Ĵ�������


}


int Window::width()
{

	return getwidth();
}


int Window::height()
{
	return getheight();
}

void Window::clear()
{
	cleardevice();

}

void Window::beginDraw()
{
	BeginBatchDraw();

}

void Window::flushDraw()
{
	FlushBatchDraw();

}

void Window::endDraw()
{

	EndBatchDraw();
}
