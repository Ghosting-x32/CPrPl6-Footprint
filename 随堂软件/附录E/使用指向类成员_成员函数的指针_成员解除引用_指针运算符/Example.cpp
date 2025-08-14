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
	Example yard(3);//�����н׶�ȷ��ָ������ĳ�Ա���ڱ����ڼ��ָ�븳ֵ
	//ָ�����ݳ�Ա�ͷ����ĳ�Աָ��
	int Example::* pt;//ָ�����Ա
	pt = &Example::inches;//����ptָ��inches
	cout << "Set pt to &Example::inches:\n";
	cout << "this->pt: " << this->*pt << endl;
	cout << "yard.*pt: " << yard.*pt << endl;

	pt = &Example::feet;//����ptָ��feet
	cout << "Set pt to &Example::feet:\n";
	cout << "this->pt: " << this->*pt << endl;
	cout << "yard.*pt: " << yard.*pt << endl;

	void (Example:: * pf)()const;//ָ���Ա����
	pf = &Example::show_in;
	cout << "Set pf to &Example::show_in:\n";
	cout << "Using (this->*pf)(): ";
	(this->*pf)();
	cout << "Using (yard.*pf)(): ";
	(yard.*pf)();


}