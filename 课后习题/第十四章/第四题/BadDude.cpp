#include"BadDude.h"


BadDude::BadDude(int num, const string& xi, const string& mi)
	:Person(xi, mi), Gunslinger(num, xi, mi), PokerPlayer(xi, mi)
{



}


void BadDude::Show()const
{
	Person::Show();
	cout << "枪手抢上的刻痕数: " << this->viewkh() << endl;
	cout << "枪手的拔枪时间: " << this->Gdraw() << " 秒" <<endl;
	cout << "扑克牌的显示: ";
	(this->Cdraw()).view();
	cout << endl;
}


Card BadDude::Cdraw()const
{
	return PokerPlayer::Draw();

	
}


 double BadDude::Gdraw()const
{
	return Gunslinger::Draw();


}
 

 void BadDude::Set()
 {
	 Gunslinger::Set();

 }
 
