#pragma once
#include<string>
#include<sstream>
#include"BasicWidget.h"
#include"Student.h"


class LineEdit : public BasicWidget
{
public:
	LineEdit(int x = 0, int y = 0, int w = 150, int h = 40);

	 
	virtual void show();
	void setTitle(const std::string& title);
	void setHitText(const std::string& text);
	const std::string& text()const;
	void clear();
	void setText(const std::string& text);


	bool textChanged();

private:

	std::string m_prevText;
	std::string m_text;
	std::string m_title;
	std::string m_hitText;



};

