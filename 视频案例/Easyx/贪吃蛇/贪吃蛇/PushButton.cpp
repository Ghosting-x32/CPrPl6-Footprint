#include "PushButton.h"


PushButton::PushButton(std::string text, int x, int y, int w, int h)
	:BasicWidget(x,y,w,h),m_text(text)
{


}

void PushButton::show()
{
	setfillcolor(cur_c);
	solidroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);

	settextcolor(RGB(0, 255, 54));
	int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;

	outtextxy(tx, ty, m_text.c_str());




}





