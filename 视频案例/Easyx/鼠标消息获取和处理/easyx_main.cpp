#include <easyx.h>		// 引用图形库头文件
#include<iostream>

using namespace std;



void mousexxcl();

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色

	mousexxcl();


	
	system("pause");
	return 0;
}




void mousexxcl()//鼠标消息获取和处理
{
	ExMessage msg = { 0 };


	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN://左键按下
			{
				cout << "左键按下" << " pos坐标：" << msg.x << "," << msg.y << endl;//相对于绘制窗口的坐标而不是电脑屏幕
			}
			break;
			case WM_RBUTTONDOWN://右键按下
			{
				cout << "右键按下" << " pos坐标：" << msg.x << "," << msg.y << endl;
			}
			break;
			case WM_MBUTTONDOWN://中键按下
			{
				cout << "中键按下" << " pos坐标：" << msg.x << "," << msg.y << endl;
			}
			break;
			case WM_MOUSEWHEEL://滚轮滚动
			{
				cout << "滚轮滚动" << "dir: " << msg.wheel << endl;
			}
			break;
			case WM_LBUTTONDBLCLK://左键双击
			{
				cout << "左键双击" << " pos坐标：" << msg.x << "," << msg.y << endl;
			}
			break;
			case WM_MOUSEMOVE://鼠标移动
			{
				//cout << "鼠标移动" << " pos坐标：" << msg.x << "," << msg.y << endl;
			}
			break;
	
			}

		}

	}


}