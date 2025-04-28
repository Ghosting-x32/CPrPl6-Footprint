#include"PokerPlayer.h"


PokerPlayer::PokerPlayer(const string& xi, const string& mi)
	:Person(xi, mi)
{


}


Card PokerPlayer::Draw()const
{
	string hs1 = "heitao";
	string hs2 = "hongtao";
	string hs3 = "meihua";
	string hs4 = "fangkuai";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis_int(1, 13);
	uniform_int_distribution<> dis_int1(1, 4000);

	int mz = dis_int(gen);
	int mz1 = dis_int1(gen);
	string hs;

	if (mz1 >= 1 && mz1 <= 1000)
	{
		hs = hs1;
	}
	else if (mz1 >= 1001 && mz1 <= 2000)
	{
		hs = hs2;
	}
	else if (mz1 >= 2001 && mz1 <= 3000)
	{
		hs = hs3;
	}
	else
	{
		hs = hs4;
	}


	Card c1(hs, mz);
	return c1;//返回函数体内的临时对象时，只能按值传递（返回值不能是引用或指针），函数生命周期结束时，栈内数据会被释放

}


void PokerPlayer::Show()const
{
	Person::Show();
	cout << "扑克牌的显示: ";
	(this->Draw()).view();
	cout << endl;
}

void PokerPlayer::Set()
{
	Person::Set();

}