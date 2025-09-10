#pragma once
#include<iostream>
#include<conio.h>
#include<easyx.h>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<memory>
#include<algorithm>


#include"Window.h"
#include"PushButton.h"
#include"Student.h"
#include"Table.h"
#include"LineEdit.h"
#include"boost/lexical_cast.hpp"

using namespace std;



class Management
{
	enum Operator
	{
		Display,
		Add,
		Erase,
		Modify,
		Search,
		Tuic,
		Menu = 66

	};



public:
	Management();
	~Management();

	void drawBackground();

	//启动管理类
	void run();


	int menu();

	//1.显示所有学生
	void display();
	//2.添加
	void add();
	//3.删除
	void erase();
	//4.修改
	void modify();
	//5.查找
	void search();

	void eventLoop();

	void readFile(const std::string& fileName);
	void saveFile(const std::string& fileName);

	void updateShowTable();



private:
	
	IMAGE m_bk;
	vector<PushButton*>menu_btns;

	std::string m_header;
	vector<Student> vec_stu;

	Table* m_showTable;

	//添加学生按钮
	unique_ptr<PushButton> m_addBtn;
	unique_ptr<LineEdit> m_addEdit;
	//删除学生
	unique_ptr<PushButton> m_delBtn;
	unique_ptr<LineEdit> m_delEdit;
	unique_ptr<Table> m_delTable;
	//查找学生
	unique_ptr<PushButton> m_serchBtn;
	unique_ptr<LineEdit> m_serchEdit;
	unique_ptr<Table> m_serchTable;
	//修改学生
	unique_ptr<LineEdit> m_modifyEdit;
	bool isFind;
	vector<unique_ptr<LineEdit>> m_stuEdit;
	vector<Student>::iterator m_modifyIt;
	 

};

