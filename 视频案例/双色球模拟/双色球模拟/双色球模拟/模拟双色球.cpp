#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;

void tex1(int val)
{
	cout << val << " ";
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	//uniform_int_distribution<> dis(1, 100);

	vector<int>hongse;
	vector<int>lanse;

	for (int i = 1; i < 34; i++)//׼������
	{
		hongse.push_back(i);
	}

	for_each(hongse.begin(), hongse.end(), tex1);
	cout << endl;
	cout << "����׼��������" << endl;
	system("pause");

	for (int i = 1; i < 17; i++)//׼������
	{
		lanse.push_back(i);
	}

	for_each(lanse.begin(), lanse.end(), tex1);
	cout << endl;
	cout << "����׼��������" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	
	cout << "Ԥϴ��5��׼����" << endl;
	system("pause");
	for (int i = 0; i < 5; i++)//Ԥϴ��5��
	{
		shuffle(hongse.begin(), hongse.end(), gen);
		cout << hongse.size() << endl;
		for_each(hongse.begin(), hongse.end(), tex1);
		cout << endl;

		shuffle(lanse.begin(), lanse.end(), gen);
		cout << lanse.size() << endl;
		for_each(lanse.begin(), lanse.end(), tex1);
		cout << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
	}

	cout << "ϴ�Ƴɹ���" << endl;
	system("pause");
	system("cls");


	cout << "\n\n***�����***\n" << endl;
	system("pause");
	//���ɫ��
	int i = 1;
	vector<int>hongsejg;
	hongsejg.resize(6);
	for (vector<int>::iterator it = hongse.begin(); it != hongse.end() && i < 7; it++ , i++)
	{
		for (int i = 0; i < 3; i++)
		{
			shuffle(hongse.begin(), hongse.end(), gen);
		}
		
		cout << "���ڹ��� " << hongse.size() << " ������" << endl;
		cout << "�� " << i << " ������ĺ���" << hongse[33 - i] << endl;
		hongsejg[i - 1] = hongse[33 - i];

		hongse.pop_back();

		cout << "ʣ��������£�" << endl;
		for_each(hongse.begin(), hongse.end(), tex1);
		cout << endl;

		cout << "-------------------------------------" << endl;
	}
	cout << "���ڹ��� " << hongse.size() << " ������" << endl;
	cout << "-------------------------------------" << endl;

	system("pause");
	cout << "\n\n***������***\n" << endl;
	system("pause");
	//����ɫ��
	int lansejg = 0;
	for (int i = 0; i < 3; i++)//ϴ��3��
	{
		shuffle(lanse.begin(), lanse.end(), gen);
	}

	cout << "���ڹ��� " << lanse.size() << " ������" << endl;
	cout << "�� 1 �����������" << lanse[15] << endl;
	lansejg = lanse[15];
	lanse.pop_back();
	cout << "ʣ����������£�" << endl;
	for_each(lanse.begin(), lanse.end(), tex1);
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "���ڹ��� " << lanse.size() << " ������" << endl;
	cout << "-------------------------------------" << endl;
	system("pause");

	//���ս��չʾ
	cout << "\n\n\n***��ɫ�����ս��***" << endl;
	cout << "=================================================" << endl;
	for_each(hongsejg.begin(), hongsejg.end(), tex1);
	cout << endl;
	cout << "=================================================" << endl;

	

	cout << "\n\n\n***��ɫ�����ս��***" << endl;
	cout << "=================================================" << endl;
	cout << lansejg << endl;
	cout << "=================================================" << endl;










	system("pause");
	return 0;
}