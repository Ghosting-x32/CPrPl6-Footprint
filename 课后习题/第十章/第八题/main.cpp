#include<iostream>
#include"list.h"
using namespace std;

void fanx(Item&);

int main()
{
	List drf;
	Item gb = { "钢笔", 360 };
	Item qb = { "铅笔", 120 };
	Item yzb = { "圆珠笔", 960 };
	cout << "当前列表储存状态：";
	if (drf.sfkong())
		cout << "当前列表为空！" << endl;
	else if (drf.sfman())
		cout << "当前列表已满！" << endl;
	else
		cout << "当前列表非空非满！" << endl;
	cout << "当前列表内容：" << endl;
	drf.visit(fanx); 
	if (drf.sfkong())
		drf.tianj(gb);
	else
		cout << "当前列表已满，无法添加任何数据！\a" << endl;
	if (!drf.sfman())
		drf.tianj(qb);
	else
		cout << "当前列表已满，无法添加任何数据！\a" << endl;
	if (!drf.sfman())
		drf.tianj(yzb);
	else
		cout << "当前列表已满，无法添加任何数据！\a" << endl;
	cout << "当前列表储存状态：";
	if (drf.sfkong())
		cout << "当前列表为空！" << endl;
	else if (drf.sfman())
		cout << "当前列表已满！" << endl;
	else
		cout << "当前列表非空非满！" << endl;
	cout << "当前列表内容：" << endl;
	drf.visit(fanx);
	








	system("pause");
	return 0;
}

void fanx(Item& x)
{
	cout << "该种笔的名字是：" << x.name << endl;
	cout << "该种笔的数量是：" << x.SL << endl;
}