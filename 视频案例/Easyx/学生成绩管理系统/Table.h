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

	void setRowCount(int row);//设置行数
	void setColCount(int col);//设置列数
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
	//查找学生用到
	void eraseDY();
	int sizeCZ();
	void updat_cckzf(int cckzf);



private:
	int m_row;
	int m_col;
	std::string m_header;

	//格子的宽度和高度
	int m_gridW;
	int m_gridH;

	int m_tw;
	int m_th;
	std::vector<std::string> m_datas;


	//分页处理
	int m_curPage;//当前页
	int m_maxPage;//最大页数
	int m_extraData;//如果不是整数页，最后一页的数据条数

	PushButton* m_prevBtn;
	PushButton* m_nextBtn;
	PushButton* m_firstBtn;
	PushButton* m_lastBtn;


	int m_cckzf;

};

