#include <easyx.h>		// ����ͼ�ο�ͷ�ļ�
#include<string>
#include"boost/lexical_cast.hpp"

void drawShape();
void drawText();

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ

	//drawShape();
	solidrectangle(0, 0, 640, 480);//����Ĭ���б�����ɫ���ʹ��ڱ�����ɫһ����������ɫ�ľ��ε�ס���ڣ��Ա��ڹ۲�Ч��

	drawText();
	
	system("pause");
	return 0;
}


void drawShape()//����ͼ�λ���
{

	putpixel(320, 240, BLACK);//��һ����

	setlinecolor(WHITE);//��������ɫ
	setlinestyle(PS_SOLID, 3);//�����ߵĸ�ʽ
	line(0, 0, getwidth(), getheight());//����
	//line(0, 0, 640, 480);//����

	setlinecolor(BLACK);
	rectangle(100, 0, 200, 100);//��������Σ�ֻ�б߿�
	setfillcolor(RED);//���������ɫ
	fillrectangle(100, 0 + 100, 200, 100 + 100);//��������Σ��б߿�Ҳ����䣩
	solidrectangle(100, 100 + 100, 200, 200 + 100);//��������Σ�ֻ����䣩

	setfillcolor(BLUE);
	roundrect(100 + 110, 0, 200 + 110, 100, 30, 30);//��Բ�Ǿ��Σ�ֻ�б߿�
	fillroundrect(210, 0 + 100, 310, 100 + 100, 30, 30);//��Բ�Ǿ��Σ��б߿�Ҳ����䣩
	solidroundrect(210, 100 + 100, 310, 200 + 100, 30, 30);//��Բ�Ǿ��Σ�ֻ����䣩

	circle(320, 240, 100);	// ��Բ��Բ��(200, 200)���뾶 100��ֻ�б߿�
	fillcircle(320, 240 + 210, 100);// ��Բ���б߿�Ҳ����䣩
	solidcircle(320 + 210, 240, 100);// ��Բ��ֻ����䣩

	ellipse(210 + 110, 0, 310 + 110, 50);//����Բ��ֻ�б߿�
	fillellipse(320, 0 + 50, 420, 50 + 50);// ����Բ���б߿�Ҳ����䣩
	solidellipse(320, 50 + 50, 420, 100 + 50); //����Բ��ֻ����䣩



}


void drawText()//��������
{
	settextstyle(100, 0, "΢���ź�");
	//settextstyle(100, 0, _T("΢���ź�"));//��Ҫ���ַ���Unicode�µȼ���const wchar_t*
	//settextstyle(100, 0, L"΢���ź�");//��Ҫ���ַ���Unicode�µȼ���const wchar_t*
	settextcolor(BROWN);
	setbkmode(TRANSPARENT);//ȥ�����ֵı�����ɫ����Ϊ͸��


	//"hello EasyX!"��const char_t*(const char*)
	outtextxy(100, 100, "hello EasyX!");
	//outtextxy(100, 100, _T("hello EasyX!"));//��Ҫ���ַ���Unicode�µȼ���const wchar_t*--------ʹ�ô��κ꣬��ϵͳ������ʲô�ַ�1.����һ���ڲ�ͬ��ϵͳ�������Ƽ�ʹ�������
	//outtextxy(100, 100, L"hello EasyX!");//��Ҫ���ַ���Unicode�µȼ���const wchar_t*-----ֱ�ӱ����ÿ��ַ�2.������
	//void outtextxy(int x, int y, LPCTSTR str);	
	//3.������------�˵���->��Ŀ->����->�߼�->�ַ���->��UNICODE��Ϊ���ֽ��ַ�������ͬһ��ϵͳ�������Ƽ�ʹ�������---��ǰ����ʹ�����
	int score = 66;
	std::string scorestr = boost::lexical_cast<std::string>(score);//ʹ��boost�������lexical_cast����ֵת��Ϊ�ַ���
	outtextxy(440, 0, scorestr.c_str());//ʹ��string�����c_str()������string�����ת��Ϊc�����ַ���


}