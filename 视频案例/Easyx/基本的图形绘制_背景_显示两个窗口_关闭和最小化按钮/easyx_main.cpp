#include <easyx.h>		// 引用图形库头文件

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色

	
	putpixel(320, 240, BLACK);//画一个点

	setlinecolor(WHITE);//设置线颜色
	setlinestyle(PS_SOLID, 3);//设置线的格式
	line(0, 0, getwidth(), getheight());//画线
	//line(0, 0, 640, 480);//画线
	
	setlinecolor(BLACK);
	rectangle(100, 0, 200, 100);//画常规矩形（只有边框）
	setfillcolor(RED);//设置填充颜色
	fillrectangle(100, 0 + 100, 200, 100 + 100);//画常规矩形（有边框也有填充）
	solidrectangle(100, 100 + 100, 200, 200 + 100);//画常规矩形（只有填充）

	setfillcolor(BLUE);
	roundrect(100 + 110, 0, 200 + 110, 100, 30, 30);//画圆角矩形（只有边框）
	fillroundrect(210, 0 + 100, 310, 100 + 100, 30, 30);//画圆角矩形（有边框也有填充）
	solidroundrect(210, 100 + 100, 310, 200 + 100, 30, 30);//画圆角矩形（只有填充）

	circle(320, 240, 100);	// 画圆，圆心(200, 200)，半径 100（只有边框）
	fillcircle(320, 240 + 210, 100);// 画圆（有边框也有填充）
	solidcircle(320 + 210, 240, 100);// 画圆（只有填充）

	ellipse(210 + 110, 0, 310 + 110, 50);//画椭圆（只有边框）
	fillellipse(320, 0 + 50, 420, 50 + 50);// 画椭圆（有边框也有填充）
	solidellipse(320, 50 + 50, 420, 100 + 50); //画椭圆（只有填充）

	system("pause");
	return 0;
}