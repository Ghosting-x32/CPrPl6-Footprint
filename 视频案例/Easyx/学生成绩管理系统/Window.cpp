#include "Window.h"


//ExMessage Window::m_msg;//c++17之前这样做


Window::Window(int w, int h, int flag)
{
	this->m_handle = initgraph(w, h, flag);
	setbkmode(TRANSPARENT);
	//也可以用GetHWnd()----获取窗口句柄
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

	SetWindowText(this->m_handle, title.c_str());//使用Windows API修改窗口名称


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
