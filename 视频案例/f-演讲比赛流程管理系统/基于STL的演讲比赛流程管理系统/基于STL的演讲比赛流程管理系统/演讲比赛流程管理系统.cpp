#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>

#include"SpeechManager.h"
#include"Speaker.h"



using namespace std;
void printMap(const map<int, Speaker>& mp);


int main()
{
	srand((unsigned int)time(0));
	SpeechManager sm;
	int choice = 0;


	while (true)
	{
		sm.show_Menu();
		//printMap(sm.m_Speaker);//����12��ѡ�ֵĴ���
		cout << "���������ѡ��" << endl;
		while (!(cin >> choice))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "�����������������֣�" << endl;
		}

		if (choice == 1)
		{
			sm.startSpeech();
		}
		else if (choice == 2)
		{
			sm.showRecord();
		}
		else if (choice == 3)
		{
			sm.clearRecord();
		}
		else if (choice == 0)
		{
			sm.exitSystem();
		}
		else
		{
			system("cls");
			cout << "�����������������룡" << endl;
		}
		//switch (choice)
		//{
		//case 1:
		//{		
		//	sm.startSpeech();
		//}		
		//	break;
		//case 2:
		//	break;
		//case 3:
		//	break;
		//case 0:
		//	sm.exitSystem();
		//	break;
		//default:
		//{
		//	system("cls");
		//	cout << "�����������������룡" << endl;
		//}
		//break;
		//}
	}






	system("pause");
	return 0;
}

void printMap(const map<int, Speaker>& mp)
{
	for (map<int, Speaker>::const_iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "��ţ�" << it->first << "\t������" << it->second.m_Name << "\t�ɼ���" << it->second.m_Score[0] << endl;
	}
	cout << endl;
}