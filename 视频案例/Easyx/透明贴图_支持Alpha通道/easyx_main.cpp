#include <easyx.h>
#include"EasyXPNG.h"






int main()
{
	initgraph(1280, 720, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ


	IMAGE img_mm;//1.����ͼƬ����
	loadimage(&img_mm, "assets/fy.png", 128, 72);//2.����ͼƬ
	//putimage(0, 0, &img_mm);//3.���ͼƬ


	EasyXPNG::TransparentImage(100, 100, &img_mm);


	system("pause");
	return 0;
}


