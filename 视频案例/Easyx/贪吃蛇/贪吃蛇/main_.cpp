#include<iostream>
#include<easyx.h>
#include<string>
#include<deque>
#include<random>//���������
#include<chrono>//��ȡʱ���


#include<Windows.h>
#include<mmsystem.h>//��������

#include"EasyXPNG.h"
#include"point.h"
#include"BasicWidget.h"
#include"PushButton.h"


using namespace std;

#pragma comment(lib, "winmm.lib")


const int WIDTH = 54;//������Ӹ���
const int HEIGHT = 36;//������Ӹ���
const int SIZE_G = 20;//���ӿ��

int socor = 0;
const int SOCOR_YZ = 10;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
deque<Point> snake;
Direction dir;
Point food(0, 0, SIZE_G, SIZE_G);
bool gameOver;//��Ϸ�����жϣ�trueΪ��Ϸ����
int ysxs = 1;//�ߵĳ�ʼ����ɫϵ��
ExMessage msg;
int sudu = 10;//��Ϸ��ʼʱ�ߵ��ƶ��ٶ�
PushButton ksyx("��ʼ��Ϸ", WIDTH* SIZE_G + 10, 0 + 10, 180, 70);
PushButton cxyx("���¿�ʼ", WIDTH* SIZE_G + 10, HEIGHT * SIZE_G - 10 - 70, 180, 70);
int yxkg = 0;//��Ϸ���أ�0��ͣ���ڼ��ؽ��棬1����ͣ���ڼ��ؽ��棬2��������Ϸ
bool existyx;//�˳���Ϸ��true��Ϊ�˳���Ϸ
int yxjstj = 0;//��Ϸ��������0����Ϸ���ڽ��У�1��ײ��ǽ�ˣ�2��ײ��������
HWND handle;//���ھ��������������Ϸ���涥������

int cx_yy = 1;//���ư�ť��Ч��ϵ��
int bk_yy = 1;
long long xucs = 0;//��¼ѭ���Ĵ���




void Setup();
void scsw();
void initGame();
void Draw();
void Input();
void Logic();

void updateWithoutInput();







int main()
{
	Setup();
	initGame();

	while (true)
	{
		//auto start = std::chrono::high_resolution_clock::now();//����ѭ��һ�����ĵ�ʱ��

		xucs = xucs + 1;
		if (xucs % 40000 == 0)
		{
			bk_yy = bk_yy + 1;//��ѭ������������һ��ѭ�����ĵ�ʱ�������ƶ�ò���һ�α�������
		}
		
		string ex_bg1 = "open images/bk.mp3 alias bgm";
		string ex_bg2 = to_string(bk_yy);
		string ex_bg = ex_bg1 + ex_bg2;
		mciSendString(ex_bg.c_str(), nullptr, 0, nullptr);//��������----��������

		string exb_bg1 = "play bgm";
		string exb_bg = exb_bg1 + ex_bg2;
		mciSendString(exb_bg.c_str(), nullptr, 0, nullptr);//��������

		string ext_bg1 = "setaudio bgm";
		string ext_bg2 = " volume to 50";
		string ext_bg = ext_bg1 + ex_bg2 + ext_bg2;
		mciSendString(ext_bg.c_str(), nullptr, 0, nullptr);//��������---������Χ0-1000
		/*ExMessage msg1;
		if (peekmessage(&msg1, EX_MOUSE))
		{
			cxyx.getmsg(msg1);
		}*/

		if (cxyx.isClicked())
		{
			cx_yy = cx_yy + 1;
			string index1 = "open images/an.mp3 alias cxbgm";
			string index2 = to_string(cx_yy);
			string index = index1 + index2;
			mciSendString(index.c_str(), nullptr, 0, nullptr);//��������----��������

			string indexb_1 = "play cxbgm";
			string indexb = indexb_1 + index2;
			mciSendString(indexb.c_str(), nullptr, 0, nullptr);//��������

			string indext_1 = "setaudio cxbgm";
			string indext_2 = " volume to 100";
			string indext = indext_1 + index2 + indext_2;
			mciSendString(indext.c_str(), nullptr, 0, nullptr);//��������---������Χ0-1000
			Setup();
			yxkg = 0;

		}
	
		Draw();
		updateWithoutInput();//���Ƽ���
		Input();//���Ƽ���
		
		//Logic();
		

	/*	auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;*/

	}
	EndBatchDraw();
	
	
	
	system("pause");
	return 0;
}


void scsw()
{
	random_device rd;
	uniform_int_distribution<> dis(0, 2147483647);
	bool onSnake;

	do
	{
		auto time_seed = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��  
		mt19937 gen(rd() ^ time_seed);
		food.set_x((dis(gen) % WIDTH) * SIZE_G);
		auto time_seed1 = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��
		mt19937 gen1(rd() ^ time_seed1);
		food.set_y((dis(gen1) % HEIGHT) * SIZE_G);
		auto time_seed2 = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��
		mt19937 gen2(rd() ^ time_seed2);
		food.set_colr_xs(dis(gen2) % 37);
		//food.set_colr(LIGHTGREEN);

		onSnake = false;
		for (auto& p : snake)
		{
		/*	food.retn_x() >= p.retn_x() && food.retn_x() <= p.retn_x() + p.retn_w();
			food.retn_y() >= p.retn_y() && food.retn_y() <= p.retn_y() + p.retn_h();
			food.retn_x() + food.retn_w() >= p.retn_x() && food.retn_x() + food.retn_w() <= p.retn_x() + p.retn_w();
			food.retn_y() + food.retn_h() >= p.retn_y() && food.retn_y() + food.retn_h() <= p.retn_y() + p.retn_h();*/

			if (
				(food.retn_x() >= p.retn_x() && food.retn_x() <= p.retn_x() + p.retn_w()
					&& food.retn_y() >= p.retn_y() && food.retn_y() <= p.retn_y() + p.retn_h())
				&& (food.retn_x() + food.retn_w() >= p.retn_x() && food.retn_x() + food.retn_w() <= p.retn_x() + p.retn_w()
					&& food.retn_y() + food.retn_h() >= p.retn_y() && food.retn_y() + food.retn_h() <= p.retn_y() + p.retn_h())
				)
			{
				onSnake = true;

				break;

			}
		}

	} while (onSnake);



}


void Setup()
{
	gameOver = false;
	existyx = false;
	dir = RIGHT;
	snake.clear();
	socor = 0;
	sudu = 300;


	//��ʼ������

	snake.push_front(Point(WIDTH / 2 * SIZE_G - SIZE_G, HEIGHT / 2 * SIZE_G, SIZE_G, SIZE_G, ysxs + 2));
	//snake.push_front(Point((WIDTH * SIZE_G - SIZE_G * 3) / 2 + SIZE_G, (HEIGHT * SIZE_G - SIZE_G) / 2, SIZE_G, SIZE_G, ysxs + 1));
	snake.push_front(Point(WIDTH / 2 * SIZE_G, HEIGHT / 2 * SIZE_G, SIZE_G, SIZE_G, ysxs + 1));
	snake.push_front(Point(WIDTH / 2 * SIZE_G + SIZE_G, HEIGHT / 2 * SIZE_G, SIZE_G, SIZE_G, ysxs));


	scsw();

	

}




void initGame()
{
	//BeginBatchDraw();
	//cleardevice();

	
	handle = initgraph((WIDTH + 10) * SIZE_G, HEIGHT * SIZE_G);//����
	setbkcolor(LIGHTGRAY);
	SetWindowText(handle, "�����С����");//ʹ��Windows API�޸Ĵ�������
}


void Draw()
{
	


	BeginBatchDraw();
	cleardevice();

	

	IMAGE bk_cor;
	loadimage(&bk_cor, "images/gezi.png");
	EasyXPNG::TransparentImage(WIDTH * SIZE_G, 0, &bk_cor);
	EasyXPNG::TransparentImage(WIDTH * SIZE_G + bk_cor.getwidth(), 0, &bk_cor);

	setbkmode(TRANSPARENT);
	ksyx.event();
	//system("pause");
	settextstyle(40, 0, "����");
	ksyx.show();

	cxyx.event();
	settextstyle(40, 0, "����");
	cxyx.show();

	//ksyx.show();
	string def_str = "�÷�";
	settextstyle(50, 0, "����");
	settextcolor(RGB(0, 255, 54));

	outtextxy((WIDTH + 10) * SIZE_G - bk_cor.getwidth() * 2 + (bk_cor.getwidth() * 2 - textwidth(def_str.c_str())) / 2, (HEIGHT * SIZE_G - textheight(def_str.c_str())) / 2 - textheight(def_str.c_str()) - 10, def_str.c_str());

	string socor_str = to_string(socor);
	outtextxy((WIDTH + 10) * SIZE_G - 200 + (200 - textwidth(socor_str.c_str())) / 2, (HEIGHT * SIZE_G - textheight(socor_str.c_str())) / 2, socor_str.c_str());



	if (yxkg != 0)
	{
		

		setlinecolor(WHITE);
		for (int i = 0; i <= WIDTH; i++)//����������
		{
			line(i * SIZE_G, 0, i * SIZE_G, HEIGHT * SIZE_G);
		}

		for (int i = 0; i < HEIGHT; i++)//�����Ӻ���
		{
			line(0, i * SIZE_G, WIDTH * SIZE_G, i * SIZE_G);
		}


		//FlushBatchDraw();
		//EndBatchDraw();


		


		snake.front().set_colr();//����ͷ
		setfillcolor(snake.front().retn_colr());
		fillrectangle(snake.front().retn_x(), snake.front().retn_y(), snake.front().retn_x() + snake.front().retn_w(), snake.front().retn_y() + snake.front().retn_h());

		for (auto it = snake.begin() + 1; it != snake.end(); ++it)//������
		{

			it->set_colr();
			setfillcolor(it->retn_colr());
			fillrectangle(it->retn_x(), it->retn_y(), it->retn_x() + it->retn_w(), it->retn_y() + it->retn_h());

		}


		food.set_colr();//��ʳ��
		setfillcolor(food.retn_colr());
		fillrectangle(food.retn_x(), food.retn_y(), food.retn_x() + food.retn_w(), food.retn_y() + food.retn_h());
	}

	


	if (yxkg == 0)
	{
		string yxjs_wsm = "�����ߣ�����";
		string yxjs = "�����С������Ϸ";
		settextstyle(100, 0, "����");
		settextcolor(RGB(255, 0, 0));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2, yxjs.c_str());
		settextstyle(50, 0, "����");
		settextcolor(RGB(255, 0, 200));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs_wsm.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2 + 80, yxjs_wsm.c_str());
		settextcolor(RGB(0, 255, 54));

	}

	if (gameOver && yxjstj == 1)
	{
		string yxjs_wsm = "ײ��ǽ����";
		string yxjs = "��Ϸ����";
		settextstyle(200, 0, "����");
		settextcolor(RGB(255, 0, 0));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2, yxjs.c_str());

		settextstyle(50, 0, "����");
		settextcolor(RGB(255, 0, 200));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs_wsm.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2 + 120, yxjs_wsm.c_str());
		settextcolor(RGB(0, 255, 54));
	}

	if (gameOver && yxjstj == 2)
	{
		string yxjs_wsm = "ײ��������";
		string yxjs = "��Ϸ����";
		settextstyle(200, 0, "����");
		settextcolor(RGB(255, 0, 0));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2, yxjs.c_str());

		settextstyle(50, 0, "����");
		settextcolor(RGB(255, 0, 200));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs_wsm.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2 + 120, yxjs_wsm.c_str());
		settextcolor(RGB(0, 255, 54));


	}

	if (existyx)
	{
		cleardevice();

		IMAGE bk_cor;
		loadimage(&bk_cor, "images/gezi.png");
		EasyXPNG::TransparentImage(WIDTH * SIZE_G, 0, &bk_cor);
		EasyXPNG::TransparentImage(WIDTH * SIZE_G + bk_cor.getwidth(), 0, &bk_cor);

		setbkmode(TRANSPARENT);
		ksyx.event();
		//system("pause");
		settextstyle(40, 0, "����");
		ksyx.show();

		cxyx.event();
		settextstyle(40, 0, "����");
		cxyx.show();

		//ksyx.show();
		string def_str = "�÷�";
		settextstyle(50, 0, "����");
		settextcolor(RGB(0, 255, 54));

		outtextxy((WIDTH + 10) * SIZE_G - bk_cor.getwidth() * 2 + (bk_cor.getwidth() * 2 - textwidth(def_str.c_str())) / 2, (HEIGHT * SIZE_G - textheight(def_str.c_str())) / 2 - textheight(def_str.c_str()) - 10, def_str.c_str());

		string socor_str = to_string(socor);
		outtextxy((WIDTH + 10) * SIZE_G - 200 + (200 - textwidth(socor_str.c_str())) / 2, (HEIGHT * SIZE_G - textheight(socor_str.c_str())) / 2, socor_str.c_str());

		string yxjs_wsm = "������ǰ������Ϸ";
		string yxjs = "��Ϸ����";
		settextstyle(200, 0, "����");
		settextcolor(RGB(255, 0, 0));
		outtextxy((WIDTH * SIZE_G  - textwidth(yxjs.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2, yxjs.c_str());

		settextstyle(50, 0, "����");
		settextcolor(RGB(255, 0, 200));
		outtextxy((WIDTH * SIZE_G - textwidth(yxjs_wsm.c_str())) / 2, (HEIGHT * SIZE_G - textheight(yxjs.c_str())) / 2 + 120, yxjs_wsm.c_str());
		settextcolor(RGB(0, 255, 54));
	}

	



	FlushBatchDraw();
	
}


void Input()
{
	if (peekmessage(&msg, EX_KEY | EX_MOUSE))
	{
		if(msg.message == WM_KEYDOWN)
		{
			switch (msg.vkcode)
			{
			case VK_UP:
			case 'W':
			{
				if (dir != DOWN)
				{
					dir = UP;
					if (!gameOver)
					{
						Logic();//��������----������������⣬�ߵ�����ֻ�ܿ��������ƶ���---���gameOver�����
					}
					
					
				}
			}
					break;
			case VK_DOWN:
			case 'S':
			{
				if (dir != UP)
				{
					dir = DOWN;
					if (!gameOver)
					{
						Logic();
					}
					
				}
			}
				break;
			case VK_LEFT:
			case 'A':
			{
				if (dir != RIGHT)
				{
					dir = LEFT;
					if (!gameOver)
					{
						Logic();
					}
				}
			}
				break;
			case VK_RIGHT:
			case 'D':
			{
				if (dir != LEFT)
				{
					dir = RIGHT;
					if (!gameOver)
					{
						Logic();
					}
				}
			}
				break;
			case VK_ESCAPE://��ǰ������Ϸ
			{
				


				existyx = true;
				gameOver = true;
			

		
				yxkg = 1;
			/*	getchar();
				getchar();
				exit(666);*/

			}
				break;
			}
			
		}
		else
		{
			//������
		/*	if (msg.message == WM_MOUSEMOVE)
			{
				cout << "shumyi" << endl;
			}*/
		
			//cout << msg.x << " " << msg.y << endl;
			ksyx.getmsg(msg);
			cxyx.getmsg(msg);
			//system("pause");
		}
	}

}


void Logic()
{
	if (ksyx.isClicked())
	{
		cx_yy = cx_yy + 1;
		string index1 = "open images/an.mp3 alias ksbgm";
		string index2 = to_string(cx_yy);
		string index = index1 + index2;
		mciSendString(index.c_str(), nullptr, 0, nullptr);//��������----��������

		string indexb_1 = "play ksbgm";
		string indexb = indexb_1 + index2;
		mciSendString(indexb.c_str(), nullptr, 0, nullptr);//��������

		string indext_1 = "setaudio ksbgm";
		string indext_2 = " volume to 100";
		string indext = indext_1 + index2 + indext_2;
		mciSendString(indext.c_str(), nullptr, 0, nullptr);//��������---������Χ0-1000






		
		yxkg = 2;
	}



	if (yxkg == 2)
	{
		Point head = snake.front();
		Point newHead = head;
		switch (dir)
		{

		case LEFT:
		{
			newHead.set_x(newHead.retn_x() - SIZE_G);
		}
		break;
		case RIGHT:
		{
			newHead.set_x(newHead.retn_x() + SIZE_G);
		}
		break;
		case UP:
		{
			newHead.set_y(newHead.retn_y() - SIZE_G);
		}
		break;
		case DOWN:
		{
			newHead.set_y(newHead.retn_y() + SIZE_G);
		}
		break;

		}

		//ײǽ���
		if (newHead.retn_x() + SIZE_G > WIDTH * SIZE_G || newHead.retn_x() < 0 || newHead.retn_y() + SIZE_G > HEIGHT * SIZE_G || newHead.retn_y() < 0)
		{
			//cout << "hhhhh" << endl;
			gameOver = true;
			yxjstj = 1;
			yxkg = 1;


			
			//cout << "ײ��ǽ" << endl;
			return;

		}

		//�������
		for (auto p = snake.begin() + 1; p != snake.end(); ++p)
		{
			if (
				//(food.retn_x() >= p.retn_x() && food.retn_x() <= p.retn_x() + p.retn_w()
				//&& food.retn_y() >= p.retn_y() && food.retn_y() <= p.retn_y() + p.retn_h())
				//&& (food.retn_x() + food.retn_w() >= p.retn_x() && food.retn_x() + food.retn_w() <= p.retn_x() + p.retn_w()
				//&& food.retn_y() + food.retn_h() >= p.retn_y() && food.retn_y() + food.retn_h() <= p.retn_y() + p.retn_h())
				(newHead.retn_x() >= p->retn_x() && newHead.retn_x() <= p->retn_x() + p->retn_w()
					&& newHead.retn_y() >= p->retn_y() && newHead.retn_y() <= p->retn_y() + p->retn_h())
				&& (newHead.retn_x() + newHead.retn_w() >= p->retn_x() && newHead.retn_x() + newHead.retn_w() <= p->retn_x() + p->retn_w()
					&& newHead.retn_y() + newHead.retn_h() >= p->retn_y() && newHead.retn_y() + newHead.retn_h() <= p->retn_y() + p->retn_h())
				)
			{
				gameOver = true;
				yxjstj = 2;
				yxkg = 1;




				//cout << "ײ������" << endl;
				return;
			}

		}
		//�ƶ���
		snake.push_front(newHead);
		for (auto p = snake.begin() + 1; p != snake.end(); ++p)
		{
			if (p->retn_colr_xs() >= 36)
			{
				p->set_colr_xs(1);
			}
			else
			{
				p->set_colr_xs(p->retn_colr_xs() + 1);
			}


		}


		//�Ե�ʳ����
		if (
			(food.retn_x() >= snake.front().retn_x() && food.retn_x() <= snake.front().retn_x() + snake.front().retn_w()
				&& food.retn_y() >= snake.front().retn_y() && food.retn_y() <= snake.front().retn_y() + snake.front().retn_h())
			&& (food.retn_x() + food.retn_w() >= snake.front().retn_x() && food.retn_x() + food.retn_w() <= snake.front().retn_x() + snake.front().retn_w()
				&& food.retn_y() + food.retn_h() >= snake.front().retn_y() && food.retn_y() + food.retn_h() <= snake.front().retn_y() + snake.front().retn_h())
			)
		{
			scsw();

			socor = socor + 100;
			sudu = sudu - 10;
		
			if (sudu <= 0)
			{
				sudu = 1;
			}

		}
		else
		{
			snake.pop_back();
		}
	}

	

}


void updateWithoutInput()
{
	if (gameOver)
	{
		return;
	}

	if (yxkg != 2)
	{
		Logic();
	}
	else
	{
		
		static long long waitIndex = 1;//�������ƶ��ٶ�
		waitIndex++;
		//cout << sudu << endl;
		//cout << waitIndex << endl;
		if (waitIndex % sudu == 0)//�������дwaitIndex = sudu�ж�����
			//�����ǰ��һֱ�Ӵ��ں��ߺ�ѭ��һֱ��ǰ�߼ӣ���Զ��������ں��ߣ�����if�������Ĵ�����Զ������ִ��
		{
			Logic();
			waitIndex = 1;
		}
		//Sleep(50);
	}

	
}