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

	//����������
	void run();


	int menu();

	//1.��ʾ����ѧ��
	void display();
	//2.���
	void add();
	//3.ɾ��
	void erase();
	//4.�޸�
	void modify();
	//5.����
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

	//���ѧ����ť
	unique_ptr<PushButton> m_addBtn;
	unique_ptr<LineEdit> m_addEdit;
	//ɾ��ѧ��
	unique_ptr<PushButton> m_delBtn;
	unique_ptr<LineEdit> m_delEdit;
	unique_ptr<Table> m_delTable;
	//����ѧ��
	unique_ptr<PushButton> m_serchBtn;
	unique_ptr<LineEdit> m_serchEdit;
	unique_ptr<Table> m_serchTable;
	//�޸�ѧ��
	unique_ptr<LineEdit> m_modifyEdit;
	bool isFind;
	vector<unique_ptr<LineEdit>> m_stuEdit;
	vector<Student>::iterator m_modifyIt;
	 

};

