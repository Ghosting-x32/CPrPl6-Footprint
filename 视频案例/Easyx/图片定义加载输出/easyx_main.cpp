#include <easyx.h>		// 引用图形库头文件
#include<iostream>

using namespace std;





int main()
{
	initgraph(1500, 1000, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色


	IMAGE img_mm;//1.定义图片变量
	loadimage(&img_mm, "assets/bizhi.jpg");//2.加载图片
	putimage(0, 0, &img_mm);//3.输出图片


	
	system("pause");
	return 0;
}


