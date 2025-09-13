#pragma once
#include<string>
#include<easyx.h>

#include "BasicWidget.h"




class PushButton : public BasicWidget
{
public:
	PushButton(std::string text = "BUTTON",int x = 0, int y = 0, int w = 100, int h = 30);

	virtual void show();

	


private:

	std::string m_text;





};

