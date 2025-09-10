#include <easyx.h>
#include<string>
#include<iostream>
#include<time.h>
#include"boost/lexical_cast.hpp"
#include"EasyXPNG.h"


using namespace std;



int main()
{
	initgraph(1280, 720, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ


	IMAGE img_mm[4];
	string str;
	string str1 = "assets/fj";
	string str2 = ".png";
	string str3;

	for (int i = 0; i < 4; i++)
	{
		int lsstr = i + 1;
		str3 = boost::lexical_cast<string>(lsstr);
		str = str1 + str3 + str2;
		//cout << str << endl;
		loadimage(img_mm + i, str.c_str());
	}



	int index = 0;
	int speed = 300;
	const int FST = 1000 / 60;
	int ffst = 0;
	int ft = 0;
	
	
	while (true)
	{
		ffst = clock();//���ص�ֵ�ǳ�����������˵�ʱ��





		BeginBatchDraw();
		cleardevice();
	

		EasyXPNG::TransparentImage(100, 100, img_mm + index);
		


		EndBatchDraw();
		/*if (index == 3)
		{

			ft = clock() - ffst;
			if (ft <= FST)
			{
				Sleep(FST - ft + speed);
			}
			
			cleardevice();
			break;
		}*/
		//cout << clock() << " ";
		//system("pause");
		index = ((clock() - 200) / speed) % 4;//��һ��ѭ��ʱ����ȷ��speed����clock()----��������0��ʼ���
	
		//cout << index << endl;


		ft = clock() - ffst;
		if (ft <= FST)
		{
			Sleep(FST - ft);
		}

		
	}

	

	system("pause");
	return 0;
}


