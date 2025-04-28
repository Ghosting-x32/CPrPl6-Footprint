#include"Tv.h"

Remote::Remote(int m, int zt)
{
	this->mode = m;
	this->m_zutai = zt;
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


void Remote::set_chan(Tv& t, int c)
{

	t.channel = c;
}


void Remote::set_mode(Tv& t)
{
	t.set_mode();

}


void Remote::set_input(Tv& t)
{
	t.set_input();

}


void Remote::viewzt()
{
	cout << "当前是: " << ((this->m_zutai == Cha) ? "Cha" : "Hud") << " 模式!" << endl;

}


//void set_m_zutai(Remote& rt)
//{
//
//	rt.m_zutai = (rt.m_zutai == Remote::Cha) ? Remote::Hud : Remote::Cha;
//}