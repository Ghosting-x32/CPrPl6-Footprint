#include <easyx.h>		// 引用图形库头文件
#include<iostream>

using namespace std;



void button();

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//重置背景颜色

	button();


	
	system("pause");
	return 0;
}


void button()
{
	setfillcolor(RGB(255, 255, 237));
	int b1x = 10;
	int b1y = 10;
	int b1w = 200;
	int b1h = 50;
	int b1yj = 20;
	fillroundrect(b1x, b1y, b1x + b1w, b1y + b1h, b1yj, b1yj);

	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char str1[] = "Start Game";
	int hSpace1 = (b1w - textwidth(str1)) / 2;
	int vSpace1 = (b1h - textheight(str1)) / 2;
	outtextxy(b1x + hSpace1, b1y + vSpace1, str1);


	int b2x = 640 - b1x - b1w;
	int b2y = b1y;
	int b2w = b1w;
	int b2h = b1h;
	int b2yj = b1yj;
	fillroundrect(b2x, b2y, b2x + b2w, b2y + b2h, b2yj, b2yj);
	char str2[] = "End Game";
	int hSpace2 = (b2w - textwidth(str2)) / 2;
	int vSpace2 = (b2h - textheight(str2)) / 2;
	outtextxy(b2x + hSpace2, b2y + vSpace2, str2);


	ExMessage msg = { 0 };

	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if (msg.x >= b1x && msg.x <= (b1x + b1w) && msg.y >= b1y && msg.y <= (b1y + b1h))
				{

					cout << "游戏开始！！" << endl;
				}

				if (msg.x >= b2x && msg.x <= (b2x + b2w) && msg.y >= b2y && msg.y <= (b2y + b2h))
				{

					cout << "游戏结束！！" << endl;
				}


			}
			break;

			}

		}
	}

	

}
