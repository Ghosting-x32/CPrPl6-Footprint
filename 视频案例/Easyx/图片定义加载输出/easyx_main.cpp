#include <easyx.h>		// ����ͼ�ο�ͷ�ļ�
#include<iostream>

using namespace std;





int main()
{
	initgraph(1500, 1000, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ


	IMAGE img_mm;//1.����ͼƬ����
	loadimage(&img_mm, "assets/bizhi.jpg");//2.����ͼƬ
	putimage(0, 0, &img_mm);//3.���ͼƬ


	
	system("pause");
	return 0;
}


