#ifndef SPEECHMANAGER_H_
#define SPEECHMANAGER_H_
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

#include"Speaker.h"
#include"PrintInt.h"



using namespace std;



class SpeechManager
{
public:
	vector<int>v1;//存放12名选手
	vector<int>v2;//存放第一轮晋级的6名选手
	vector<int>vvictory;//存放第二轮晋级的3名选手
	map<int, Speaker>m_Speaker;//存放编号对应的选手
	int m_Index;//比赛轮数
	bool fileIsEmpty;//判断文件为空的标志
	map<int, vector<string>>m_Record;//存放往届记录




	SpeechManager();

	~SpeechManager();
	void show_Menu();
	void exitSystem();
	void initSpeech();
	void createSpeaker();
	void startSpeech();
	void speechDraw();
	void speechContest();
	void showScore();
	void saveRecord();
	void loadRecord();
	void showRecord();
	void clearRecord();
};



#endif 

