#include"Example.h"


Example::Example()
{
	this->feet = 0;
	this->inches = 0;

}


Example::Example(int ft)
{
	this->feet = ft;
	this->inches = 12 * this->feet;

}


Example::~Example()
{


}


void Example::show_in()const
{
	cout << this->inches << " inches\n";

}


void Example::show_ft()const
{

	cout << this->feet << " feet\n";
}


void Example::use_ptr()const
{
	Example yard(3);//在运行阶段确定指针关联的成员，在编译期间给指针赋值
	//指向数据成员和方法的成员指针
	int Example::* pt;//指向类成员
	pt = &Example::inches;//现在pt指向inches
	cout << "Set pt to &Example::inches:\n";
	cout << "this->pt: " << this->*pt << endl;
	cout << "yard.*pt: " << yard.*pt << endl;

	pt = &Example::feet;//现在pt指向feet
	cout << "Set pt to &Example::feet:\n";
	cout << "this->pt: " << this->*pt << endl;
	cout << "yard.*pt: " << yard.*pt << endl;

	void (Example:: * pf)()const;//指向成员函数
	pf = &Example::show_in;
	cout << "Set pf to &Example::show_in:\n";
	cout << "Using (this->*pf)(): ";
	(this->*pf)();
	cout << "Using (yard.*pf)(): ";
	(yard.*pf)();


}