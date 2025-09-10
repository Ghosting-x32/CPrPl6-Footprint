#include <easyx.h>
#include"EasyXPNG.h"






int main()
{
	initgraph(1280, 720, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色


	IMAGE img_mm;//1.定义图片变量
	loadimage(&img_mm, "assets/fy.png", 128, 72);//2.加载图片
	//putimage(0, 0, &img_mm);//3.输出图片


	EasyXPNG::TransparentImage(100, 100, &img_mm);


	system("pause");
	return 0;
}


