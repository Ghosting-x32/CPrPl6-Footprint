#include"Screen.h"



Screen::Screen(pos ht, pos wd, char c)
	:height(ht), width(wd), contents(ht * wd, c)
{


}

Screen::Screen(pos ht, pos wd)
	:height(ht), width(wd), contents(ht * wd, ' ')
{


}






void Screen::some_member()const
{
	++access_ctr;

}