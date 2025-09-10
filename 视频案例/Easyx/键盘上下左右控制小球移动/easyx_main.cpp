#include <easyx.h>		// ����ͼ�ο�ͷ�ļ�
#include<iostream>

using namespace std;

void button1();



int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ

	button1();

	
	system("pause");
	return 0;
}


void button1()//С���ƶ�
{
	ExMessage msg = { 0 };
	int yq_x = 10;
	int yq_y = 10;
	int yq_r = 10;
	int speed = 3;
	int vx = 0;
	int vy = 0;


	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE | EX_KEY))
		{

		}

		if (msg.message == WM_KEYDOWN)
		{
			switch (msg.vkcode)
			{
			case VK_UP:
			{
				vy = -1;
			}
				break;
			case VK_DOWN:
			{
				vy = 1;
			}
				break;
			case VK_LEFT:
			{
				vx = -1;

			}
				break; 
			case VK_RIGHT:
			{
				vx = 1;
			}
				break;
			}

		}
		else if (msg.message == WM_KEYUP)
		{

			switch (msg.vkcode)
			{
			case VK_UP:
			{
				vy = 0;
			}
			break;
			case VK_DOWN:
			{
				vy = 0;
			}
			break;
			case VK_LEFT:
			{
				vx = 0;

			}
			break;
			case VK_RIGHT:
			{
				vx = 0;
			}
			break;
			}

		}




		BeginBatchDraw();
		cleardevice();

		setfillcolor(BLACK);
		solidcircle(yq_x, yq_y, yq_r);
		yq_x += speed * vx;
		yq_y += speed * vy;





		EndBatchDraw();

		Sleep(10);
		msg.message = 0;


	}



}