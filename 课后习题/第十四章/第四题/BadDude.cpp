#include"BadDude.h"


BadDude::BadDude(int num, const string& xi, const string& mi)
	:Person(xi, mi), Gunslinger(num, xi, mi), PokerPlayer(xi, mi)
{



}


void BadDude::Show()const
{
	Person::Show();
	cout << "ǹ�����ϵĿ̺���: " << this->viewkh() << endl;
	cout << "ǹ�ֵİ�ǹʱ��: " << this->Gdraw() << " ��" <<endl;
	cout << "�˿��Ƶ���ʾ: ";
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
 
