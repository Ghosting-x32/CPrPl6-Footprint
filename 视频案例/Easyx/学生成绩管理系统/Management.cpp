#include "Management.h"

Management::Management()
{
	isFind = false;
	loadimage(&m_bk, "images/bk.jpg");

	this->readFile("images/xscj.txt");


	settextstyle(24, 0, "楷体");


	menu_btns.push_back(new PushButton("查看学生"));
	menu_btns.push_back(new PushButton("添加学生"));
	menu_btns.push_back(new PushButton("删除学生"));
	menu_btns.push_back(new PushButton("修改学生"));
	menu_btns.push_back(new PushButton("查找学生"));
	menu_btns.push_back(new PushButton("退出系统"));

	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->setFixedSize(300, 50);

		int jige = 20;//添加了按钮的间隔
		int mx = (Window::width() - menu_btns[i]->width()) / 2;
		
		int my_sp = (Window::height() - menu_btns.size() * menu_btns[i]->heigh() - ((menu_btns.size() - 1) * jige)) / 2;//y坐标起始移动位置

		int my = i * menu_btns[i]->heigh() + i * 20;
		menu_btns[i]->move(mx, my_sp + my);

	}

	m_showTable = new Table;
	m_showTable->setRowCount(13);
	m_showTable->setHeader(m_header);
	updateShowTable();
	
	m_showTable->move((Window::width() - m_showTable->width()) / 2, 100);//调整表格水平方向居中


	//添加学生
	//m_addBtn.reset(new PushButton("添加", 900, 400, 80, 40));
	m_addBtn.reset(new PushButton("添加", (Window::width() - 80) / 2 + 300, (Window::height() - 40) / 2 + 60, 80, 40));


	//(Window::width() - m_addEdit->width()) / 2 - 90
	//(Window::height() - m_addEdit->heigh()) / 2 - 280
	//m_addEdit.reset(new LineEdit(250, 400, 600, 40));
	m_addEdit.reset(new LineEdit((Window::width() - 600) / 2 - 90, (Window::height() - 40) / 2 + 60, 600, 40));
	m_addEdit->setTitle("请输入学生信息");
	m_addEdit->setHitText("请按照\n\t<学号 姓名 班级 数学 语文 英语>\n格式输入学生信息");
	//删除学生

	//m_delBtn.reset(new PushButton("删除", 770, 400, 80, 40));
	m_delBtn.reset(new PushButton("删除", (Window::width() - 80) / 2 + 170, (Window::height() - 40) / 2 + 60, 80, 40));

	//m_delEdit.reset(new LineEdit(420, 400, 300, 40));
	m_delEdit.reset(new LineEdit((Window::width() - 300) / 2 - 70, (Window::height() - 40) / 2 + 60, 300, 40));
	m_delEdit->setTitle("请输入需要删除的学生的学号");
	m_delEdit->setHitText("请输入需要删除的学生的学号");
	 
	m_delTable.reset(new Table);
	//m_delTable->setRowCount(1);
	m_delTable->setHeader(m_header);
	m_delTable->move((Window::width() - m_delTable->width()) / 2, m_delEdit->y() + 120);

	//查找学生
	m_serchBtn.reset(new PushButton("查找", (Window::width() - 80) / 2 + 170, (Window::height() - 40) / 2 + 60, 80, 40));
	m_serchEdit.reset(new LineEdit((Window::width() - 300) / 2 - 70, (Window::height() - 40) / 2 + 60, 300, 40));
	m_serchEdit->setTitle("请输入需要查找的学生的学号");
	m_serchEdit->setHitText("请输入需要查找的学生的学号");

	m_serchTable.reset(new Table);
	m_serchTable->setHeader(m_header);
	m_serchTable->move((Window::width() - m_delTable->width()) / 2, m_delEdit->y() + 120);

	//修改学生
	m_modifyEdit.reset(new LineEdit((Window::width() - 300) / 2, (Window::height() - 40) / 2 - 40, 300, 40));
	m_modifyEdit->setTitle("请输入需要修改的学生的学号");
	m_modifyEdit->setHitText("请输入需要修改的学生的学号");

	for (int i = 0; i < 6; i++)
	{
		m_stuEdit.emplace_back(new LineEdit);
		m_stuEdit[i]->move((Window::width() - 6 * m_stuEdit[i]->width() - 5 * 10) / 2 + i * m_stuEdit[i]->width() + i * 10, (Window::height() - 40) / 2 + 10);//加上了10像素间隔

		switch (i)
		{
		case 0:
		{
			m_stuEdit[i]->setTitle("请输入需要修改的学生的学号");
			m_stuEdit[i]->setHitText("请输入需要修改的学生的学号");

		}
			break;
		case 1:
		{
			m_stuEdit[i]->setTitle("请输入需要修改的学生的姓名");
			m_stuEdit[i]->setHitText("请输入需要修改的学生的姓名");

		}
			break;
		case 2:
		{
			m_stuEdit[i]->setTitle("请输入需要修改的学生的班级");
			m_stuEdit[i]->setHitText("请输入需要修改的学生的班级");

		}
			break;
		case 3:
		{
			m_stuEdit[i]->setTitle("请输入需要修改的学生的数学分数");
			m_stuEdit[i]->setHitText("请输入需要修改的学生的数学分数");

		}
			break;
		case 4:
		{
			m_stuEdit[i]->setTitle("请输入需要修改的学生的语文分数");
			m_stuEdit[i]->setHitText("请输入需要修改的学生的语文分数");

		}
			break;
		case 5:
		{
			m_stuEdit[i]->setTitle("请输入需要修改的学生的英语分数");
			m_stuEdit[i]->setHitText("请输入需要修改的学生的英语分数");

		}
			break;

		}

	}
	m_modifyIt = vec_stu.end();






}


Management::~Management()
{
	if (this->m_showTable != nullptr)
	{
		delete this->m_showTable;
		this->m_showTable = nullptr;
	}

	if (this->menu_btns.size() != 0)
	{
		for (auto* btn : menu_btns)//auto*只是声明btn是一个指针（没有解引用的说法），直接获取容器中的指针（无额外拷贝）
		{
			delete btn;
			btn = nullptr;
		}


	}

}

void Management::drawBackground()
{
	putimage(0, 0, &m_bk);

}

void Management::run()
{
	//cout << "run" << endl;
	
	int op = Menu;

	Window::beginDraw();
	while (true)
	{
		//if (_kbhit())//用Windows API检测键盘输入-------在命令符窗口下按esc才有用
		// 键盘鼠标消息对应命令符窗口
		//{
		//	if (_getch() == 27)
		//	{
		//		op = Menu;
		//	}

		//}
		Window::clear();
		drawBackground();

		

		if (Window::hasMsg())//用easyx库检测键盘输入-------在绘制窗口下按esc才有用
			//键盘鼠标消息对应绘制窗口
		{

			
			switch (Window::getMsg().message)
			{
			case WM_KEYDOWN://按键按下---多按几下esc消息会停留在消息流里（类似输入流），直到下一次检测到消耗丢掉
			//case WM_KEYUP://按键弹起
			{
				

				if (Window::getMsg().vkcode == VK_ESCAPE)
				{
					
					op = Menu;					
				}
			}
				break;
			default:
				eventLoop();//鼠标操作

				break;

			}

		}



		switch (op)
		{
		case Display:
		{
			display();
		}
			break;
		case Add:
		{
			add();
		}
			break;
		case Erase:
		{
			erase();
		}
			break;
		case Modify:
		{
			modify();
		}
			break;
		case Search:
		{
			search();
		}
			break;
		case Menu:
		{
			op = menu();
			
				
		}
			break;	
		case Tuic:
		{
			this->saveFile("images/xscj.txt");
			exit(666);
		}
			break;
		}
		Window::flushDraw();
		Window::getMsg().message = 0;

	}
	Window::endDraw();

}

int Management::menu()
{
	//int op = -1;
	//outtextxy(0, 0, "menu");
	//Window::flushDraw();
	//cout << "menu" << endl;
	//cin >> op;
	
	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->event();
		if (menu_btns[i]->isClicked())
		{
			return i;
		}	

	}

	return Menu;
}

void Management::display()
{
	//outtextxy(0, 0, "display");
	m_showTable->show();
	//cout << "display" << endl;
}

void Management::add()
{
	const char* title = "请输入学生信息<学号 姓名 班级 数学 语文 英语>";
	settextstyle(36, 0, "楷体");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2, title);
	settextstyle(24, 0, "楷体");

	m_addBtn->show();
	m_addEdit->show();

	auto str = m_addEdit->text();


	
	

	if (m_addBtn->isClicked() && !str.empty())
	{
		//cout << __FUNCTION__ << endl;//输出函数名
		//cout << m_addEdit->text() << endl;	
		vec_stu.push_back(Student::fromString(str));

		
		std::replace(str.begin(),str.end(), ' ', '\t');//替换迭代器之间（字符串中）的字符

		m_showTable->insertData(str);
		this->saveFile("images/xscj.txt");
		cout << "\a";
		m_addEdit->clear();
	
		const char* tjcg = "添加成功";
		settextcolor(RED);
		settextstyle(60, 0, "楷体");
		outtextxy((Window::width() - textwidth(tjcg)) / 2, (Window::height() - textheight(tjcg)) / 2 + 200, tjcg);
		settextcolor(BLACK);
		settextstyle(24, 0, "楷体");
	
		Window::flushDraw();//释放缓冲区
		Sleep(1200);
		
	
	}

	
	


	//cout << "add" << endl;
}

void Management::erase()
{

	const char* title = "请输入需要删除的学生的学号";
	settextstyle(36, 0, "楷体");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2, title);
	settextstyle(24, 0, "楷体");

	m_delBtn->show();
	m_delEdit->show();

	if (m_delTable->rowCount() != 0)
	{
		m_delTable->show();
	}
	

	auto& str = m_delEdit->text();
	if (m_delEdit->textChanged())
	{
		auto it = find_if(vec_stu.begin(), vec_stu.end(), [=](const Student& stu)
			{
				
				//string inedex = boost::lexical_cast<string> (stu.m_number);
				string inedex = to_string(stu.m_number);//两种方法都可以
				return inedex == str;

			});

		if (it == vec_stu.end())
		{
			cout << "\a";
			string tisici1 = "对不起，没有找到学号为";
			string tisici2 = "的学生";
			string tisici = tisici1 + str + tisici2;
			settextcolor(RED);
			settextstyle(46, 0, "楷体");
			outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
			settextstyle(24, 0, "楷体");
			settextcolor(BLACK);
			Window::flushDraw();//释放缓冲区
			Sleep(2000);

		}
		else
		{

			m_delTable->insertData(it->formatInfo());

		}
		//m_delEdit->clear();
		
	}
	
	if (m_delBtn->isClicked() && !str.empty())
	{

		auto it = remove_if(vec_stu.begin(), vec_stu.end(), [=](const Student& stu)//查找到符合条件的成员之后，把该成员移动到容器的最后
			{

				//string inedex = boost::lexical_cast<string> (stu.m_number);
				string inedex = to_string(stu.m_number);//两种方法都可以
				return inedex == str;

			});
		vec_stu.erase(it, vec_stu.end());
		m_showTable->clear();
		updateShowTable();
		this->saveFile("images/xscj.txt"); 
		cout << "\a";


		string tisici = "删除成功";
		settextcolor(RED);
		settextstyle(46, 0, "楷体");
		outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
		settextstyle(24, 0, "楷体");
		settextcolor(BLACK);
		Window::flushDraw();//释放缓冲区
		Sleep(2000);
		m_delTable->clear();//解决持续删除

	}

	//outtextxy(0, 0, "erase");
	//cout << "erase" << endl;
}

void Management::modify()
{

	const char* title = "请输入需要修改的学生的学号";
	settextstyle(36, 0, "楷体");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2 - 100, title);
	settextstyle(24, 0, "楷体");


	m_modifyEdit->show();
	if (isFind)
	{
		for (auto& e : m_stuEdit)
		{
			e->show();

		}
	}
	


	if (m_modifyEdit->textChanged())
	{
		auto& str = m_modifyEdit->text();
		unsigned int number;
		stringstream ss(str);
		ss >> number;
		auto it = find_if(vec_stu.begin(), vec_stu.end(), [=](const Student& stu)
			{
				return stu.m_number == number;

			});
		if (it == vec_stu.end())
		{
			isFind = false;
			m_modifyIt = vec_stu.end();


			cout << "\a";
			string tisici1 = "对不起，没有找到学号为";
			string tisici2 = "的学生";
			string tisici = tisici1 + str + tisici2;
			settextcolor(RED);
			settextstyle(46, 0, "楷体");
			outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
			settextstyle(24, 0, "楷体");
			settextcolor(BLACK);
			Window::flushDraw();//释放缓冲区
			Sleep(2000);

		}
		else
		{
			m_stuEdit[0]->setText(to_string(it->m_number));
			m_stuEdit[1]->setText(it->m_name);
			m_stuEdit[2]->setText(it->m_grade);
			m_stuEdit[3]->setText(to_string(it->m_math));
			m_stuEdit[4]->setText(to_string(it->m_chinese));
			m_stuEdit[5]->setText(to_string(it->m_english));

			isFind = true;
			m_modifyIt = it;
		}


	}

	if (isFind && m_modifyIt != vec_stu.end())
	{
		for (int i = 0; i < m_stuEdit.size(); i++)
		{
			if (m_stuEdit[i]->textChanged() && m_stuEdit[i]->isClicked())
			{
				string tisici = " ";
				switch (i)
				{
				case 0:
				{
					//cout << "hhh" << endl;
					//m_modifyIt->m_number = atoi(m_stuEdit[i]->text().c_str());//将c风格的字符串转换为数值类型--在头文件cstdlib里面
					//m_modifyIt->m_number = stoi(m_stuEdit[i]->text());//将c风格的字符串转换为数值类型（整数）--c++11之后使用stoi()提供异常处理，在名称空间std下,还可以接受string类型字符串,返回值是int
					//需要转换更大的数值，而不是int范围内的值，可以用stol()或者stoll(),返回值是long,long long 
					m_modifyIt->m_number = stoll(m_stuEdit[i]->text());

					//cout << m_modifyIt->m_number << endl;
					
					tisici = "修改学号成功";						
										
				}
					break;
				case 1:
				{
					m_modifyIt->m_name = m_stuEdit[i]->text();

					tisici = "修改姓名成功";
											
				}
					break;
				case 2:
				{
					m_modifyIt->m_grade = m_stuEdit[i]->text();

					tisici = "修改班级成功";
										
				}
					break;
				case 3:
				{
					m_modifyIt->m_math = stoll(m_stuEdit[i]->text());


					tisici = "修改数学成绩成功";										
				}
					break;
				case 4:
				{
					m_modifyIt->m_chinese = stoll(m_stuEdit[i]->text());


					tisici = "修改语文成绩成功";
										
				}
					break;
				case 5:
				{
					m_modifyIt->m_english = stoll(m_stuEdit[i]->text());

						
					tisici = "修改英语成绩成功";
									
				}
					break;
				
				}
				m_showTable->clear();//必须对原始表格数据进行清空
				updateShowTable();
				this->saveFile("images/xscj.txt");

				cout << "\a";
				settextcolor(RED);
				settextstyle(46, 0, "楷体");
				outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
				settextstyle(24, 0, "楷体");
				settextcolor(BLACK);
				Window::flushDraw();//释放缓冲区
				Sleep(2000);

				

				
			}

		}


	}

	//outtextxy(0, 0, "modify");
	//cout << "modify" << endl;
}

void Management::search()
{

	const char* title = "请输入需要查找的学生的学号";
	settextstyle(36, 0, "楷体");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2, title);
	settextstyle(24, 0, "楷体");


	m_serchBtn->show();
	m_serchEdit->show();

	if (m_serchTable->rowCount() != 0)//解决持续查找
	{
		m_serchTable->updat_cckzf(1);
		if (m_serchTable->sizeCZ() > 1)
		{
			
			m_serchTable->eraseDY();


			m_serchTable->show();
		}
		else
		{
			
			m_serchTable->show();
		}
		m_serchTable->updat_cckzf(0);
	}


	auto& str = m_serchEdit->text();
	if (m_serchBtn->isClicked() && m_serchEdit->textChanged())
	{
		auto it = find_if(vec_stu.begin(), vec_stu.end(), [=](const Student& stu)
			{

				//string inedex = boost::lexical_cast<string> (stu.m_number);
				string inedex = to_string(stu.m_number);//两种方法都可以
				return inedex == str;

			});

		if (it == vec_stu.end())
		{
			cout << "\a";
			string tisici1 = "对不起，没有找到学号为";
			string tisici2 = "的学生";
			string tisici = tisici1 + str + tisici2;
			settextcolor(RED);
			settextstyle(46, 0, "楷体");
			outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
			settextstyle(24, 0, "楷体");
			settextcolor(BLACK);
			Window::flushDraw();//释放缓冲区
			Sleep(2000);

		}
		else
		{

			m_serchTable->insertData(it->formatInfo());

		}
		//m_delEdit->clear();

	}


	//outtextxy(0, 0, "search");
	//cout << "search" << endl;
}


void Management::eventLoop()
{
	m_showTable->event();
	m_addBtn->event();
	m_addEdit->event();
	m_delBtn->event();
	m_delEdit->event();
	m_delTable->event();
	m_serchBtn->event();
	m_serchEdit->event();
	m_serchTable->event();
	m_modifyEdit->event();
	for (auto& e : m_stuEdit)
	{
		e->event();

	}

}

void Management::readFile(const std::string& fileName)
{
	ifstream read;
	read.open(fileName, ios_base::in);
	if (!read.is_open())
	{
		cerr << "文件打开失败！" << endl;
		return;
	}
	getline(read, m_header);//读取表头
	//std::cout << m_header << endl;


	while (!read.eof())//读取表格内容
	{
		std::string index = "1";
		getline(read, index);
		if (strlen(index.c_str()) == 0)//读取遇到空行结束读取
		{
			break;
		}

		Student stu;
		stringstream ss(index);//格式化写入
		ss >> stu.m_number >> stu.m_name >> stu.m_grade >> stu.m_math >> stu.m_chinese >> stu.m_english;

		vec_stu.push_back(stu);
		//cout << stu.m_number << stu.m_name << stu.m_grade << stu.m_math << stu.m_chinese << stu.m_english << endl;


	}

	read.close();

}



void Management::saveFile(const std::string& fileName)
{
	ofstream fout;
	fout.open(fileName, ios_base::out | ios_base::trunc);//如果文件存在则截短文件ios_base::app才是追加写入
	if (!fout.is_open())
	{
		cerr << "文件打开失败" << endl;
		return;

	}

	//m_header += "\n";//导致两次连续保存后出现空行，导致读取文件数据到程序时遇到空行中断，无法读取文件中的数据到程序
	fout.write(m_header.c_str(), m_header.size());
	fout << endl;

	for (auto& data : vec_stu)
	{
		string info = data.formatInfo();
		fout.write(info.c_str(), info.size());

	}



	fout.close();
}


void Management::updateShowTable()
{
	for (auto& val : vec_stu)
	{
		m_showTable->insertData(val.formatInfo());
	}


}