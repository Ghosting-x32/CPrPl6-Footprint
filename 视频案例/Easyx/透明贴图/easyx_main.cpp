#include <easyx.h>
#include <conio.h>
#include<Windows.h>
#pragma comment(lib, "Msimg32.lib")


void transparentImage(IMAGE* img, int x, int y, COLORREF transparentColor)
{
	HDC dstDC = GetImageHDC();  // ��ȡĿ��DC
	HDC srcDC = GetImageHDC(img);  // ��ȡԴͼ��DC

	// ʹ��TransparentBlt����
	TransparentBlt(
		dstDC, x, y, img->getwidth(), img->getheight(),
		srcDC, 0, 0, img->getwidth(), img->getheight(),
		transparentColor  // ָ��͸��ɫ
	);
}


int main()
{
	initgraph(1280, 720, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ


	IMAGE img_mm;//1.����ͼƬ����
	loadimage(&img_mm, "assets/fy.png", 640, 360);//2.����ͼƬ
	//putimage(0, 0, &img_mm);//3.���ͼƬ

	transparentImage(&img_mm, 0, 0, BLACK);



	system("pause");
	return 0;
}


