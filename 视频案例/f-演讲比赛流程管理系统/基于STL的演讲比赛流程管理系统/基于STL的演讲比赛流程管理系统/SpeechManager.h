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
	vector<int>v1;//���12��ѡ��
	vector<int>v2;//��ŵ�һ�ֽ�����6��ѡ��
	vector<int>vvictory;//��ŵڶ��ֽ�����3��ѡ��
	map<int, Speaker>m_Speaker;//��ű�Ŷ�Ӧ��ѡ��
	int m_Index;//��������
	bool fileIsEmpty;//�ж��ļ�Ϊ�յı�־
	map<int, vector<string>>m_Record;//��������¼




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

