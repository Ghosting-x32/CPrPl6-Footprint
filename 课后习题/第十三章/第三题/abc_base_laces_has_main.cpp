#include <iostream>
#include<string>

#include"abcDMA.h"
#include"baseDMA.h"
#include"hasDMA.h"
#include"lacksDMA.h"

using namespace std;

const int CLIENTS = 4;

int main()
{
	abcDMA* p_clients[CLIENTS];

	char* label1 = new char[50];
	int rating1 = 0;
	int m_text1 = 0;
	char* color1 = new char[50];
	char* style1 = new char[50];
	int select = 0;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "请输入label: ";
		cin >> label1;
		cout << "请输入rating: ";
		while (!(cin >> rating1))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		while (cin.get() != '\n')
		{
			continue;
		}

		cout << "请选择你要走的子类：" << endl;
		cout << "1.baseDMA" << endl;
		cout << "2.lacksDMA" << endl;
		cout << "3.hasDMA" << endl;

		while (true)
		{
			while (!(cin >> select))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "输入有误，请输入数字！" << endl;
			}
			while (cin.get() != '\n')
			{
				continue;
			}

			if (select == 1)
			{
				cout << "请输入m_text: ";
				while (!(cin >> m_text1))
				{
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cout << "输入有误，请输入数字！" << endl;
				}
				p_clients[i] = new baseDMA(m_text1, label1, rating1);

				while (cin.get() != '\n')
				{
					continue;
				}
				break;

			}
			else if (select == 2)
			{
				cout << "请输入color: ";
				cin >> color1;
				p_clients[i] = new lacksDMA(color1, label1, rating1);
				break;

			}
			else if (select == 3)
			{				
				cout << "请输入style: ";
				cin >> style1;
				p_clients[i] = new hasDMA(style1, label1, rating1);
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}


	}

	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->View();
		cout << endl;
	}
	
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	delete[] label1;
	delete[] color1;
	delete[] style1;


	system("pause");
	return 0;
}

