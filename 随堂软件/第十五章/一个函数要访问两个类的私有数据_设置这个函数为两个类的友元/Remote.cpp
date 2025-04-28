#include"Remote.h"

Remote::Remote(int m)
{
	this->mode = m;

}


bool Remote::volup(Tv& t)
{
	return t.volup();
	
}


bool Remote::voldown(Tv& t)
{
	return t.voldown();

}


void Remote::onoff(Tv& t)
{
	t.onoff();

}


void Remote::chanup(Tv& t)
{
	t.chanup();

}


void Remote::chandown(Tv& t)
{
	t.chandown();

}


void Remote::set_mode(Tv& t)
{
	t.set_mode();

}


void Remote::set_input(Tv& t)
{
	t.set_input();

}


void set_chan(Tv& t, int c)
{

	t.channel = c;
}