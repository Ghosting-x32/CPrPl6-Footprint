#include<iostream>
#include<conio.h>//����������kbhit()��getch()
#include<windows.h>//sleep()���������������
#include<deque>
#include<random>
#include<chrono>//��ȡʱ���
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
		Sleep(sudu); // ������Ϸ�ٶ�
	}
	cout << "��Ϸ������" << endl;





	system("pause");
	return 0;
}




void scsw()
{
	//����ʳ��   
	random_device rd;
	uniform_int_distribution<> dis(0, 100000);
	bool onSnake;

	do
	{
		auto time_seed = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��  
		mt19937 gen(rd() ^ time_seed);
		food.set_x(dis(gen) % width);
		auto time_seed1 = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��
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

	//��ʼ������
	int startX = width / 2;
	int startY = height / 2;
	snake.push_front(Point(startX, startY));
	snake.push_front(Point(startX + 1, startY));
	snake.push_front(Point(startX + 2, startY));

	scsw();

	// ��Setup���������ӣ�//���ع��
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(console, &cursorInfo);

}


void Draw()
{
	// ֻ�޸��������滻�������� + �Ƴ������ˢ��
	static COORD cursorPos = { 0,0 };
	static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// ʹ��SetConsoleCursorPosition���system("cls")
	SetConsoleCursorPosition(console, cursorPos);


	//system("cls");
	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= (width * 2); x++)
		{

			if (y == height)//��ǽ
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
			//if (x == width || (x == width * 2 && y != height / 2))//ȥ��������м��һ��ǽ
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
				else if (corde >= 1000 && corde < 10000)//��߷�����90000��,����λ�Ϳ�����
				{
					tuige = 11;
				}
				else
				{
					tuige = 12;
				}

				
				for (int i = 1; i < tuige; i++)//�˸��Ա�����Ӧ������м��һ��ǽ
				{
					cout << "\b";
				}
				cout << "�÷֣�" << corde;
				
			}

			if (x == snake.front().retn_x() && y == snake.front().retn_y())//����ͷ
			{
				cout << "@";
			}
			else
			{
				bool isBody = false;
				for (auto it = snake.begin() + 1; it != snake.end(); ++it)//������
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
					if (x == food.retn_x() && y == food.retn_y())//��ʳ��
					{
						cout << "F";

					}
					else
					{
						cout << " ";//��������ո����
					}

				}

			}

		}
		cout << endl;
	}

	


}


void Input()
{
	if (_kbhit())//�������Ƿ�������
	{
		switch (_getch())//���ռ��̵�����
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
	//�����µ�ͷ��
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

	//ײǽ���
	if (newHead.retn_x() < 0 || newHead.retn_x() >= width || newHead.retn_y() < 0 || newHead.retn_y() >= height)
	{
		gameOver = true;
		return;
	}


	//�������
	for (auto& p : snake)
	{
		if (p.retn_x() == newHead.retn_x() && p.retn_y() == newHead.retn_y())
		{
			gameOver = true;
			return;
		}

	}

	//�ƶ���
	snake.push_front(newHead);//�µ�ͷ��������ͷ



	//��ʳ����
	if (newHead.retn_x() == food.retn_x() && newHead.retn_y() == food.retn_y())
	{
		//������ʳ��
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
		snake.pop_back();//û�гԵ�ʳ��ɾ������β
	}


}