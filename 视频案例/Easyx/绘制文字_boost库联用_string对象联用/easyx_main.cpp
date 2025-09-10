#include <easyx.h>		// 引用图形库头文件
#include<string>
#include"boost/lexical_cast.hpp"

void drawShape();
void drawText();

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色

	//drawShape();
	solidrectangle(0, 0, 640, 480);//文字默认有背景颜色，和窗口背景颜色一样，画个白色的矩形挡住窗口，以便于观察效果

	drawText();
	
	system("pause");
	return 0;
}


void drawShape()//基本图形绘制
{

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



}


void drawText()//绘制文字
{
	settextstyle(100, 0, "微软雅黑");
	//settextstyle(100, 0, _T("微软雅黑"));//需要宽字符，Unicode下等价于const wchar_t*
	//settextstyle(100, 0, L"微软雅黑");//需要宽字符，Unicode下等价于const wchar_t*
	settextcolor(BROWN);
	setbkmode(TRANSPARENT);//去掉文字的背景颜色，改为透明


	//"hello EasyX!"是const char_t*(const char*)
	outtextxy(100, 100, "hello EasyX!");
	//outtextxy(100, 100, _T("hello EasyX!"));//需要宽字符，Unicode下等价于const wchar_t*--------使用带参宏，让系统决定用什么字符1.方法一（在不同的系统下运行推荐使用这个）
	//outtextxy(100, 100, L"hello EasyX!");//需要宽字符，Unicode下等价于const wchar_t*-----直接标明用宽字符2.方法二
	//void outtextxy(int x, int y, LPCTSTR str);	
	//3.方法三------菜单栏->项目->属性->高级->字符集->把UNICODE改为多字节字符集（在同一个系统下运行推荐使用这个）---当前代码使用这个
	int score = 66;
	std::string scorestr = boost::lexical_cast<std::string>(score);//使用boost库里面的lexical_cast将数值转换为字符串
	outtextxy(440, 0, scorestr.c_str());//使用string里面的c_str()函数将string类对象转换为c风格的字符串


}