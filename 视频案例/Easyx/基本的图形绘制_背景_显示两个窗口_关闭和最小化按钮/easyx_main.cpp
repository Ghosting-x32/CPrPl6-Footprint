#include <easyx.h>		// ����ͼ�ο�ͷ�ļ�

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ

	
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

	system("pause");
	return 0;
}