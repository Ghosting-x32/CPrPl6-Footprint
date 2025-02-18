#include<iostream>
#include"yhzh.h"

int main()
{
	using namespace std;
	Yhzh yhzh_cs = Yhzh("顾旭", "guxu1234", 600000.365);
	yhzh_cs.show();
	yhzh_cs.cun(800000.256);
	yhzh_cs.show();
	yhzh_cs.qu(1400000.000);
	yhzh_cs.show();

	system("pause");
	return 0;
}
