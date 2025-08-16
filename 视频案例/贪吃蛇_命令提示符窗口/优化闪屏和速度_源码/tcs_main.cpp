#include<iostream>
#include<conio.h>//监测键盘输入kbhit()和getch()
#include<windows.h>//sleep()阻塞程序继续运行
#include<deque>
#include<random>
#include<chrono>//获取时间戳
#include"point.h"

using namespace std;



enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

const int width = 30;
const int height = 30;
int corde = 0;
int sudu = 1000;

deque<Point> snake;
Direction dir;
Point food(0, 0);
bool gameOver;

void scsw();

void Setup();
void Draw();
void Input();
void Logic();









int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(sudu); // 控制游戏速度
	}
	cout << "游戏结束！" << endl;





	system("pause");
	return 0;
}




void scsw()
{
	//生成食物   
	random_device rd;
	uniform_int_distribution<> dis(0, 100000);
	bool onSnake;

	do
	{
		auto time_seed = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//获取高精度时间戳（微秒级）  
		mt19937 gen(rd() ^ time_seed);
		food.set_x(dis(gen) % width);
		auto time_seed1 = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//获取高精度时间戳（微秒级）
		mt19937 gen1(rd() ^ time_seed1);
		food.set_y(dis(gen1) % height);

		//cout << dis(gen) << endl << dis(gen1) << endl;

	   //food.show_x();
	   // food.show_y();

		onSnake = false;
		for (auto& p : snake)
		{
			if (p.retn_x() == food.retn_x() && p.retn_y() == food.retn_y())
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
	dir = RIGHT;
	snake.clear();

	//初始化蛇身
	int startX = width / 2;
	int startY = height / 2;
	snake.push_front(Point(startX, startY));
	snake.push_front(Point(startX + 1, startY));
	snake.push_front(Point(startX + 2, startY));

	scsw();

	// 在Setup函数最后添加：//隐藏光标
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(console, &cursorInfo);

}


void Draw()
{
	// 只修改两处：替换清屏操作 + 移除多余的刷新
	static COORD cursorPos = { 0,0 };
	static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// 使用SetConsoleCursorPosition替代system("cls")
	SetConsoleCursorPosition(console, cursorPos);


	//system("cls");
	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= (width * 2); x++)
		{

			if (y == height)//画墙
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
			//if (x == width || (x == width * 2 && y != height / 2))//去掉最左边中间的一个墙
			if (x == width || x == width * 2 )
			{
				cout << "|";
			}
			if ((y == height / 2) && (x == width + width / 2))
			{
				int tuige = 8;
				if (corde == 0)
				{
					tuige = 8;
				}
				else if(corde >= 100 && corde < 1000)
				{
					tuige = 10;
				}
				else if (corde >= 1000 && corde < 10000)//最高分数是90000分,到万位就可以了
				{
					tuige = 11;
				}
				else
				{
					tuige = 12;
				}

				
				for (int i = 1; i < tuige; i++)//退格以便于适应最左边中间的一个墙
				{
					cout << "\b";
				}
				cout << "得分：" << corde;
				
			}

			if (x == snake.front().retn_x() && y == snake.front().retn_y())//画蛇头
			{
				cout << "@";
			}
			else
			{
				bool isBody = false;
				for (auto it = snake.begin() + 1; it != snake.end(); ++it)//画蛇身
				{
					if (it->retn_x() == x && it->retn_y() == y)
					{
						cout << "*";
						isBody = true;
						break;
					}

				}
				if (!isBody)
				{
					if (x == food.retn_x() && y == food.retn_y())//画食物
					{
						cout << "F";

					}
					else
					{
						cout << " ";//其他情况空格填充
					}

				}

			}

		}
		cout << endl;
	}

	


}


void Input()
{
	if (_kbhit())//监测键盘是否有输入
	{
		switch (_getch())//接收键盘的输入
		{
		case 'a':
		{
			if (dir != RIGHT)
			{
				dir = LEFT;
			}
		}
		break;
		case 'd':
		{
			if (dir != LEFT)
			{
				dir = RIGHT;
			}
		}
		break;
		case 'w':
		{
			if (dir != DOWN)
			{
				dir = UP;
			}
		}
		break;
		case 's':
		{
			if (dir != UP)
			{
				dir = DOWN;
			}
		}
		break;
		case 'x':
		{
			gameOver = true;
		}
		break;

		}
	}


}



void Logic()
{
	//计算新的头部
	Point head = snake.front();
	Point newHead = head;
	switch (dir)
	{
	case LEFT:
	{
		int x1 = (newHead.retn_x());
		newHead.set_x(--x1);
	}
	break;
	case RIGHT:
	{
		int x1 = (newHead.retn_x());
		newHead.set_x(++x1);

	}
	break;
	case UP:
	{
		int y1 = (newHead.retn_y());
		newHead.set_y(--y1);
	}
	break;
	case DOWN:
	{

		int y1 = (newHead.retn_y());
		newHead.set_y(++y1);
	}
	break;

	}

	//撞墙检测
	if (newHead.retn_x() < 0 || newHead.retn_x() >= width || newHead.retn_y() < 0 || newHead.retn_y() >= height)
	{
		gameOver = true;
		return;
	}


	//自碰检测
	for (auto& p : snake)
	{
		if (p.retn_x() == newHead.retn_x() && p.retn_y() == newHead.retn_y())
		{
			gameOver = true;
			return;
		}

	}

	//移动蛇
	snake.push_front(newHead);//新的头插入容器头



	//吃食物检测
	if (newHead.retn_x() == food.retn_x() && newHead.retn_y() == food.retn_y())
	{
		//生成新食物
		scsw();
		corde = corde + 100;
		sudu = sudu - 100;
		if (sudu <= 0)
		{
			sudu = 1;
		}

	}
	else
	{
		snake.pop_back();//没有吃到食物删除容器尾
	}


}