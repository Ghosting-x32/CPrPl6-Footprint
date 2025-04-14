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
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
}


void SpeechManager::exitSystem()
{
	system("cls");
	cout << "欢迎下次使用！" << endl;
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
		string name = "选手";
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

void SpeechManager::startSpeech()//控制整个比赛的流程
{
	//第一轮比赛
	//1.抽签
	this->speechDraw();

	//2.比赛
	this->speechContest();

	//3.显示结果
	this->showScore();

	//第二轮比赛
	this->m_Index++;
	//1.抽签
	this->speechDraw();

	//2.比赛
	this->speechContest();

	//3.显示结果
	this->showScore();
	//4.保存分数
	this->saveRecord();

	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "---------------第 " << this->m_Index << " 轮比赛选手正在抽签！----------------" << endl << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());//需要设置种子
		for_each(this->v1.begin(), this->v1.end(), PrintInt());//使用了谓词
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
	cout << "---------------第 " << this->m_Index << " 轮比赛正式开始！--------------------" << endl << endl;

	multimap<double, int, greater<double>>groupScore;
	int num = 0;


	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
		cout << "----------第1小组打分情况：---------------" << endl;
	}
	else
	{
		v_Src = v2;
		cout << "----------第2轮比赛打分情况：---------------" << endl;
	}


	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		deque<double>d;
		cout << "编号：" << *it << "\t姓名：" << this->m_Speaker[*it].m_Name << "\t打分：";
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

		cout << "编号：" << *it << "\t姓名：" << this->m_Speaker[*it].m_Name << "\t得分：" << avg << endl << endl;
		groupScore.insert(make_pair(avg, *it));





		if (num % 6 == 0)
		{
			if (this->m_Index == 1)
			{
				cout << "----------第" << (num / 6) << "小组比赛名次：---------------" << endl;
			}
			else
			{
				cout << "----------第2轮比赛名次：---------------" << endl;
			}

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号： " << it->second << "\t姓名：" << this->m_Speaker[it->second].m_Name << "\t得分：" << it->first << endl;
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
				cout << "----------第2小组打分情况：---------------" << endl;
			}
			else
			{
				cout << endl;
			}

		}
	}
	cout << "--------------第 " << this->m_Index << " 轮比赛完毕！-------------------" << endl;
	cout << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "--------------第 " << this->m_Index << " 轮晋级选手信息如下：-------------------" << endl;
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
		cout << "编号：" << *it << "\t姓名：" << this->m_Speaker[*it].m_Name << "\t得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
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
	ofs1 << "上一届数据到此结束！" << "," << endl;

	ofs1.close();
	cout << "比赛记录数据已保存！" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs1;
	ifs1.open("speech.csv", ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "打开失败，文件不存在！" << endl;
		this->fileIsEmpty = true;
		ifs1.close();
		return;
	}

	char ch;
	ifs1 >> ch;

	if (ifs1.eof())
	{
		cout << "文件打开成功，数据内容为空！" << endl;
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
	//	cout << "届次：" << it->first << "\t冠军编号：" << it->second[0] << "\t冠军姓名：" << it->second[1] << "\t冠军得分：" << it->second[2] << endl;
	//	cout << "届次：" << it->first << "\t亚军编号：" << it->second[3] << "\t亚军姓名：" << it->second[4] << "\t亚军得分：" << it->second[5] << endl;
	//	cout << "届次：" << it->first << "\t季军编号：" << it->second[6] << "\t季军姓名：" << it->second[7] << "\t季军得分：" << it->second[8] << endl;
	//	cout << it->second[9] << endl;
	//}
	ifs1.close();
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty == true)
	{
		cout << "文件记录为空或文件不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= this->m_Record.size(); i++)
	{
		cout << "第 " << i << " 届" << endl;
		cout << "冠军编号：" << this->m_Record[i][0] << "\t冠军姓名：" << this->m_Record[i][1] << "\t冠军得分：" << this->m_Record[i][2] << endl;
		cout << "亚军编号：" << this->m_Record[i][3] << "\t亚军姓名：" << this->m_Record[i][4] << "\t亚军得分：" << this->m_Record[i][5] << endl;
		cout << "季军编号：" << this->m_Record[i][6] << "\t季军姓名：" << this->m_Record[i][7] << "\t季军得分：" << this->m_Record[i][8] << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "确认清空所有数据？" << endl;
	cout << "1.确认\n2.返回" << endl;
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
			cout << "输入错误，请输入数字！" << endl;
		}
		if (select == 1)
		{
			ofstream ofs1;
			ofs1.open("speech.csv", ios::trunc);

			this->initSpeech();
			this->createSpeaker();
			this->loadRecord();

			cout << "数据已全部清空成功！" << endl;
			break;
		}
		else if (select == 2)
		{
			cout << "已返回，文件保留成功！" << endl;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}


	system("pause");
	system("cls");
}