#pragma once
#include<string>
#include<sstream>
#include<easyx.h>
#include<vector>
#include<iostream>
#include"Window.h"
#include "BasicWidget.h"
#include"PushButton.h"
#include"boost/lexical_cast.hpp"





class Table : public BasicWidget
{
public:

	Table(int row = 0, int col = 0);
	virtual ~Table();

	void setRowCount(int row);//��������
	void setColCount(int col);//��������
	int rowCount();
	int colCount();

	void setHeader(const std::string& header);
	void insertData(const std::string& data);

	virtual void show();
	void drawTalbeGrid();
	void drawTalbeData();

	std::vector<std::string> split(std::string str, char separator);


	void updatePage();
	void drawButton();

	virtual void event();
	void drawHeader();
	void clear();
	//����ѧ���õ�
	void eraseDY();
	int sizeCZ();
	void updat_cckzf(int cckzf);



private:
	int m_row;
	int m_col;
	std::string m_header;

	//���ӵĿ�Ⱥ͸߶�
	int m_gridW;
	int m_gridH;

	int m_tw;
	int m_th;
	std::vector<std::string> m_datas;


	//��ҳ����
	int m_curPage;//��ǰҳ
	int m_maxPage;//���ҳ��
	int m_extraData;//�����������ҳ�����һҳ����������

	PushButton* m_prevBtn;
	PushButton* m_nextBtn;
	PushButton* m_firstBtn;
	PushButton* m_lastBtn;


	int m_cckzf;

};

