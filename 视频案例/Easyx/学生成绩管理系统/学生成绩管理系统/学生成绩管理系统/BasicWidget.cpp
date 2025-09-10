#include "BasicWidget.h"
BasicWidget::BasicWidget(int x, int y, int w, int h)
	:m_x(x),m_y(y),m_w(w),m_h(h)
{



}


BasicWidget::~BasicWidget()
{


}


int BasicWidget::width()
{
	return this->m_w;

}


int BasicWidget::heigh()
{
	return this->m_h;

}


void BasicWidget::setFixedSize(int w, int h)
{
	m_w = w;
	m_h = h;

}


int BasicWidget::x()
{
	return this->m_x;


}


int BasicWidget::y()
{
	return this->m_y;

}


void BasicWidget::move(int x, int y)
{
	m_x = x;
	m_y = y;

}


bool BasicWidget::isin()
{
	auto& m_msg = Window::getMsg();
	if (m_msg.x >= m_x && m_msg.x <= m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
	{
		return true;

	}
	else
	{
		return false;
	}


}



bool BasicWidget::isClicked()
{
	if (isin())
	{
		auto& m_msg = Window::getMsg();
		if (m_msg.message == WM_LBUTTONDOWN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}


void BasicWidget::event()
{


	if (!isin())
	{
		cur_c = normal_c;

	}
	else
	{
		cur_c = hover_c;
	}

}



void BasicWidget::setBackgroundColor(COLORREF& color)
{
	this->normal_c = color;


}


void BasicWidget::setHoverColor(COLORREF& color)
{

	this->hover_c = color;

}