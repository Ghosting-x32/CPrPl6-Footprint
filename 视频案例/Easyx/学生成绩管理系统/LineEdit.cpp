#include "LineEdit.h"


LineEdit::LineEdit(int x, int y, int w, int h)
	:BasicWidget(x,y,w,h)
{
	this->cur_c = RGB(214, 255, 218);
	this->normal_c = RGB(214, 255, 218);
	this->hover_c = RGB(170, 255, 180);
	//m_text = "哈哈哈哈哈";


}


void LineEdit::show()
{

	setfillcolor(cur_c);
	setlinecolor(BLACK);
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);

	settextcolor(BLACK);
	
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;

	outtextxy(m_x + 10, ty, m_text.c_str());

	if (isClicked())
	{
		char buf[128];


		InputBox(buf, 128, m_hitText.c_str(), m_title.c_str());//谈出输入对话框

		if (buf[0] != '\0')
		{
			m_text = buf;
		}
		
		
		

	}

}


void LineEdit::setTitle(const std::string& title)
{
	m_title = title;


}


void LineEdit::setHitText(const std::string& text)
{
	m_hitText = text;

}

const std::string& LineEdit::text()const
{
	return m_text;

}

void LineEdit::clear()
{

	m_text.clear();
}



bool LineEdit::textChanged()
{
	if (m_prevText == m_text)
	{

		return false;
	}
	m_prevText = m_text;
	return true;

}

void LineEdit::setText(const std::string& text)
{
	m_text = text;

}