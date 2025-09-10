#include <easyx.h>
#include <conio.h>
#include<Windows.h>
#pragma comment(lib, "Msimg32.lib")


void transparentImage(IMAGE* img, int x, int y, COLORREF transparentColor)
{
	HDC dstDC = GetImageHDC();  // 获取目标DC
	HDC srcDC = GetImageHDC(img);  // 获取源图像DC

	// 使用TransparentBlt函数
	TransparentBlt(
		dstDC, x, y, img->getwidth(), img->getheight(),
		srcDC, 0, 0, img->getwidth(), img->getheight(),
		transparentColor  // 指定透明色
	);
}


int main()
{
	initgraph(1280, 720, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色


	IMAGE img_mm;//1.定义图片变量
	loadimage(&img_mm, "assets/fy.png", 640, 360);//2.加载图片
	//putimage(0, 0, &img_mm);//3.输出图片

	transparentImage(&img_mm, 0, 0, BLACK);



	system("pause");
	return 0;
}


