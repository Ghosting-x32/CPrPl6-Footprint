#include <easyx.h>		// ����ͼ�ο�ͷ�ļ�
#include<iostream>

using namespace std;



void mousexxcl();

int main()
{
	initgraph(640, 480, EX_NOMINIMIZE | EX_NOCLOSE | EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 640x480 ����

	setbkcolor(RGB(217, 231, 151));
	cleardevice();//���ñ�����ɫ

	mousexxcl();


	
	system("pause");
	return 0;
}




void mousexxcl()//�����Ϣ��ȡ�ʹ���
{
	ExMessage msg = { 0 };


	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN://�������
			{
				cout << "�������" << " pos���꣺" << msg.x << "," << msg.y << endl;//����ڻ��ƴ��ڵ���������ǵ�����Ļ
			}
			break;
			case WM_RBUTTONDOWN://�Ҽ�����
			{
				cout << "�Ҽ�����" << " pos���꣺" << msg.x << "," << msg.y << endl;
			}
			break;
			case WM_MBUTTONDOWN://�м�����
			{
				cout << "�м�����" << " pos���꣺" << msg.x << "," << msg.y << endl;
			}
			break;
			case WM_MOUSEWHEEL://���ֹ���
			{
				cout << "���ֹ���" << "dir: " << msg.wheel << endl;
			}
			break;
			case WM_LBUTTONDBLCLK://���˫��
			{
				cout << "���˫��" << " pos���꣺" << msg.x << "," << msg.y << endl;
			}
			break;
			case WM_MOUSEMOVE://����ƶ�
			{
				//cout << "����ƶ�" << " pos���꣺" << msg.x << "," << msg.y << endl;
			}
			break;
	
			}

		}

	}


}