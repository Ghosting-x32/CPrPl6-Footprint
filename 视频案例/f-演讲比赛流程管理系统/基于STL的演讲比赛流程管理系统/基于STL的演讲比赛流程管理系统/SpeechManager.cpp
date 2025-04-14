#include"SpeechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

}

SpeechManager::~SpeechManager()
{



}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
}


void SpeechManager::exitSystem()
{
	system("cls");
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vvictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(pair<int, Speaker>((i + 10001), sp));
	}
}

void SpeechManager::startSpeech()//������������������
{
	//��һ�ֱ���
	//1.��ǩ
	this->speechDraw();

	//2.����
	this->speechContest();

	//3.��ʾ���
	this->showScore();

	//�ڶ��ֱ���
	this->m_Index++;
	//1.��ǩ
	this->speechDraw();

	//2.����
	this->speechContest();

	//3.��ʾ���
	this->showScore();
	//4.�������
	this->saveRecord();

	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "---------------�� " << this->m_Index << " �ֱ���ѡ�����ڳ�ǩ��----------------" << endl << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());//��Ҫ��������
		for_each(this->v1.begin(), this->v1.end(), PrintInt());//ʹ����ν��
		cout << endl << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for_each(this->v2.begin(), this->v2.end(), PrintInt());
		cout << endl << endl;
	}
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest()
{
	cout << "---------------�� " << this->m_Index << " �ֱ�����ʽ��ʼ��--------------------" << endl << endl;

	multimap<double, int, greater<double>>groupScore;
	int num = 0;


	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
		cout << "----------��1С���������---------------" << endl;
	}
	else
	{
		v_Src = v2;
		cout << "----------��2�ֱ�����������---------------" << endl;
	}


	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		deque<double>d;
		cout << "��ţ�" << *it << "\t������" << this->m_Speaker[*it].m_Name << "\t��֣�";
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			cout << score << " ";
			d.push_back(score);


		}
		cout << endl;

		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		cout << "��ţ�" << *it << "\t������" << this->m_Speaker[*it].m_Name << "\t�÷֣�" << avg << endl << endl;
		groupScore.insert(make_pair(avg, *it));





		if (num % 6 == 0)
		{
			if (this->m_Index == 1)
			{
				cout << "----------��" << (num / 6) << "С��������Σ�---------------" << endl;
			}
			else
			{
				cout << "----------��2�ֱ������Σ�---------------" << endl;
			}

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ� " << it->second << "\t������" << this->m_Speaker[it->second].m_Name << "\t�÷֣�" << it->first << endl;
			}

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					this->v2.push_back(it->second);
				}
				else
				{
					this->vvictory.push_back(it->second);
				}
			}
			groupScore.clear();
			cout << endl;
			if (num < 12 && this->m_Index == 1)
			{
				cout << "----------��2С���������---------------" << endl;
			}
			else
			{
				cout << endl;
			}

		}
	}
	cout << "--------------�� " << this->m_Index << " �ֱ�����ϣ�-------------------" << endl;
	cout << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "--------------�� " << this->m_Index << " �ֽ���ѡ����Ϣ���£�-------------------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vvictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << "\t������" << this->m_Speaker[*it].m_Name << "\t�÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs1;
	ofs1.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = this->vvictory.begin(); it != this->vvictory.end(); it++)
	{
		ofs1 << *it << "," << this->m_Speaker[*it].m_Name << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs1 << "��һ�����ݵ��˽�����" << "," << endl;

	ofs1.close();
	cout << "������¼�����ѱ��棡" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs1;
	ifs1.open("speech.csv", ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "��ʧ�ܣ��ļ������ڣ�" << endl;
		this->fileIsEmpty = true;
		ifs1.close();
		return;
	}

	char ch;
	ifs1 >> ch;

	if (ifs1.eof())
	{
		cout << "�ļ��򿪳ɹ�����������Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs1.close();
		return;
	}

	ifs1.putback(ch);
	string data;
	int index = 1;

	while (ifs1 >> data)//getline(ifs1, data)
	{
		vector<string>v;
		int start = 0;
		int pos = -1;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			else
			{
				string temp = data.substr(start, (pos - start));
				v.push_back(temp);
				start = pos + 1;
			}
		}
		this->m_Record.insert(pair<int, vector<string>>(index, v));
		index++;
	}

	this->fileIsEmpty = false;
	//for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
	//{
	//	cout << "��Σ�" << it->first << "\t�ھ���ţ�" << it->second[0] << "\t�ھ�������" << it->second[1] << "\t�ھ��÷֣�" << it->second[2] << endl;
	//	cout << "��Σ�" << it->first << "\t�Ǿ���ţ�" << it->second[3] << "\t�Ǿ�������" << it->second[4] << "\t�Ǿ��÷֣�" << it->second[5] << endl;
	//	cout << "��Σ�" << it->first << "\t������ţ�" << it->second[6] << "\t����������" << it->second[7] << "\t�����÷֣�" << it->second[8] << endl;
	//	cout << it->second[9] << endl;
	//}
	ifs1.close();
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty == true)
	{
		cout << "�ļ���¼Ϊ�ջ��ļ������ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= this->m_Record.size(); i++)
	{
		cout << "�� " << i << " ��" << endl;
		cout << "�ھ���ţ�" << this->m_Record[i][0] << "\t�ھ�������" << this->m_Record[i][1] << "\t�ھ��÷֣�" << this->m_Record[i][2] << endl;
		cout << "�Ǿ���ţ�" << this->m_Record[i][3] << "\t�Ǿ�������" << this->m_Record[i][4] << "\t�Ǿ��÷֣�" << this->m_Record[i][5] << endl;
		cout << "������ţ�" << this->m_Record[i][6] << "\t����������" << this->m_Record[i][7] << "\t�����÷֣�" << this->m_Record[i][8] << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "ȷ������������ݣ�" << endl;
	cout << "1.ȷ��\n2.����" << endl;
	int select = 0;
	while (true)
	{
		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "����������������֣�" << endl;
		}
		if (select == 1)
		{
			ofstream ofs1;
			ofs1.open("speech.csv", ios::trunc);

			this->initSpeech();
			this->createSpeaker();
			this->loadRecord();

			cout << "������ȫ����ճɹ���" << endl;
			break;
		}
		else if (select == 2)
		{
			cout << "�ѷ��أ��ļ������ɹ���" << endl;
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}


	system("pause");
	system("cls");
}