#include "Management.h"

Management::Management()
{
	isFind = false;
	loadimage(&m_bk, "images/bk.jpg");

	this->readFile("images/xscj.txt");


	settextstyle(24, 0, "����");


	menu_btns.push_back(new PushButton("�鿴ѧ��"));
	menu_btns.push_back(new PushButton("���ѧ��"));
	menu_btns.push_back(new PushButton("ɾ��ѧ��"));
	menu_btns.push_back(new PushButton("�޸�ѧ��"));
	menu_btns.push_back(new PushButton("����ѧ��"));
	menu_btns.push_back(new PushButton("�˳�ϵͳ"));

	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->setFixedSize(300, 50);

		int jige = 20;//����˰�ť�ļ��
		int mx = (Window::width() - menu_btns[i]->width()) / 2;
		
		int my_sp = (Window::height() - menu_btns.size() * menu_btns[i]->heigh() - ((menu_btns.size() - 1) * jige)) / 2;//y������ʼ�ƶ�λ��

		int my = i * menu_btns[i]->heigh() + i * 20;
		menu_btns[i]->move(mx, my_sp + my);

	}

	m_showTable = new Table;
	m_showTable->setRowCount(13);
	m_showTable->setHeader(m_header);
	updateShowTable();
	
	m_showTable->move((Window::width() - m_showTable->width()) / 2, 100);//�������ˮƽ�������


	//���ѧ��
	//m_addBtn.reset(new PushButton("���", 900, 400, 80, 40));
	m_addBtn.reset(new PushButton("���", (Window::width() - 80) / 2 + 300, (Window::height() - 40) / 2 + 60, 80, 40));


	//(Window::width() - m_addEdit->width()) / 2 - 90
	//(Window::height() - m_addEdit->heigh()) / 2 - 280
	//m_addEdit.reset(new LineEdit(250, 400, 600, 40));
	m_addEdit.reset(new LineEdit((Window::width() - 600) / 2 - 90, (Window::height() - 40) / 2 + 60, 600, 40));
	m_addEdit->setTitle("������ѧ����Ϣ");
	m_addEdit->setHitText("�밴��\n\t<ѧ�� ���� �༶ ��ѧ ���� Ӣ��>\n��ʽ����ѧ����Ϣ");
	//ɾ��ѧ��

	//m_delBtn.reset(new PushButton("ɾ��", 770, 400, 80, 40));
	m_delBtn.reset(new PushButton("ɾ��", (Window::width() - 80) / 2 + 170, (Window::height() - 40) / 2 + 60, 80, 40));

	//m_delEdit.reset(new LineEdit(420, 400, 300, 40));
	m_delEdit.reset(new LineEdit((Window::width() - 300) / 2 - 70, (Window::height() - 40) / 2 + 60, 300, 40));
	m_delEdit->setTitle("��������Ҫɾ����ѧ����ѧ��");
	m_delEdit->setHitText("��������Ҫɾ����ѧ����ѧ��");
	 
	m_delTable.reset(new Table);
	//m_delTable->setRowCount(1);
	m_delTable->setHeader(m_header);
	m_delTable->move((Window::width() - m_delTable->width()) / 2, m_delEdit->y() + 120);

	//����ѧ��
	m_serchBtn.reset(new PushButton("����", (Window::width() - 80) / 2 + 170, (Window::height() - 40) / 2 + 60, 80, 40));
	m_serchEdit.reset(new LineEdit((Window::width() - 300) / 2 - 70, (Window::height() - 40) / 2 + 60, 300, 40));
	m_serchEdit->setTitle("��������Ҫ���ҵ�ѧ����ѧ��");
	m_serchEdit->setHitText("��������Ҫ���ҵ�ѧ����ѧ��");

	m_serchTable.reset(new Table);
	m_serchTable->setHeader(m_header);
	m_serchTable->move((Window::width() - m_delTable->width()) / 2, m_delEdit->y() + 120);

	//�޸�ѧ��
	m_modifyEdit.reset(new LineEdit((Window::width() - 300) / 2, (Window::height() - 40) / 2 - 40, 300, 40));
	m_modifyEdit->setTitle("��������Ҫ�޸ĵ�ѧ����ѧ��");
	m_modifyEdit->setHitText("��������Ҫ�޸ĵ�ѧ����ѧ��");

	for (int i = 0; i < 6; i++)
	{
		m_stuEdit.emplace_back(new LineEdit);
		m_stuEdit[i]->move((Window::width() - 6 * m_stuEdit[i]->width() - 5 * 10) / 2 + i * m_stuEdit[i]->width() + i * 10, (Window::height() - 40) / 2 + 10);//������10���ؼ��

		switch (i)
		{
		case 0:
		{
			m_stuEdit[i]->setTitle("��������Ҫ�޸ĵ�ѧ����ѧ��");
			m_stuEdit[i]->setHitText("��������Ҫ�޸ĵ�ѧ����ѧ��");

		}
			break;
		case 1:
		{
			m_stuEdit[i]->setTitle("��������Ҫ�޸ĵ�ѧ��������");
			m_stuEdit[i]->setHitText("��������Ҫ�޸ĵ�ѧ��������");

		}
			break;
		case 2:
		{
			m_stuEdit[i]->setTitle("��������Ҫ�޸ĵ�ѧ���İ༶");
			m_stuEdit[i]->setHitText("��������Ҫ�޸ĵ�ѧ���İ༶");

		}
			break;
		case 3:
		{
			m_stuEdit[i]->setTitle("��������Ҫ�޸ĵ�ѧ������ѧ����");
			m_stuEdit[i]->setHitText("��������Ҫ�޸ĵ�ѧ������ѧ����");

		}
			break;
		case 4:
		{
			m_stuEdit[i]->setTitle("��������Ҫ�޸ĵ�ѧ�������ķ���");
			m_stuEdit[i]->setHitText("��������Ҫ�޸ĵ�ѧ�������ķ���");

		}
			break;
		case 5:
		{
			m_stuEdit[i]->setTitle("��������Ҫ�޸ĵ�ѧ����Ӣ�����");
			m_stuEdit[i]->setHitText("��������Ҫ�޸ĵ�ѧ����Ӣ�����");

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
		for (auto* btn : menu_btns)//auto*ֻ������btn��һ��ָ�루û�н����õ�˵������ֱ�ӻ�ȡ�����е�ָ�루�޶��⿽����
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
		//if (_kbhit())//��Windows API����������-------������������°�esc������
		// ���������Ϣ��Ӧ���������
		//{
		//	if (_getch() == 27)
		//	{
		//		op = Menu;
		//	}

		//}
		Window::clear();
		drawBackground();

		

		if (Window::hasMsg())//��easyx�����������-------�ڻ��ƴ����°�esc������
			//���������Ϣ��Ӧ���ƴ���
		{

			
			switch (Window::getMsg().message)
			{
			case WM_KEYDOWN://��������---�ఴ����esc��Ϣ��ͣ������Ϣ�����������������ֱ����һ�μ�⵽���Ķ���
			//case WM_KEYUP://��������
			{
				

				if (Window::getMsg().vkcode == VK_ESCAPE)
				{
					
					op = Menu;					
				}
			}
				break;
			default:
				eventLoop();//������

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
	const char* title = "������ѧ����Ϣ<ѧ�� ���� �༶ ��ѧ ���� Ӣ��>";
	settextstyle(36, 0, "����");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2, title);
	settextstyle(24, 0, "����");

	m_addBtn->show();
	m_addEdit->show();

	auto str = m_addEdit->text();


	
	

	if (m_addBtn->isClicked() && !str.empty())
	{
		//cout << __FUNCTION__ << endl;//���������
		//cout << m_addEdit->text() << endl;	
		vec_stu.push_back(Student::fromString(str));

		
		std::replace(str.begin(),str.end(), ' ', '\t');//�滻������֮�䣨�ַ����У����ַ�

		m_showTable->insertData(str);
		this->saveFile("images/xscj.txt");
		cout << "\a";
		m_addEdit->clear();
	
		const char* tjcg = "��ӳɹ�";
		settextcolor(RED);
		settextstyle(60, 0, "����");
		outtextxy((Window::width() - textwidth(tjcg)) / 2, (Window::height() - textheight(tjcg)) / 2 + 200, tjcg);
		settextcolor(BLACK);
		settextstyle(24, 0, "����");
	
		Window::flushDraw();//�ͷŻ�����
		Sleep(1200);
		
	
	}

	
	


	//cout << "add" << endl;
}

void Management::erase()
{

	const char* title = "��������Ҫɾ����ѧ����ѧ��";
	settextstyle(36, 0, "����");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2, title);
	settextstyle(24, 0, "����");

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
				string inedex = to_string(stu.m_number);//���ַ���������
				return inedex == str;

			});

		if (it == vec_stu.end())
		{
			cout << "\a";
			string tisici1 = "�Բ���û���ҵ�ѧ��Ϊ";
			string tisici2 = "��ѧ��";
			string tisici = tisici1 + str + tisici2;
			settextcolor(RED);
			settextstyle(46, 0, "����");
			outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
			settextstyle(24, 0, "����");
			settextcolor(BLACK);
			Window::flushDraw();//�ͷŻ�����
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

		auto it = remove_if(vec_stu.begin(), vec_stu.end(), [=](const Student& stu)//���ҵ����������ĳ�Ա֮�󣬰Ѹó�Ա�ƶ������������
			{

				//string inedex = boost::lexical_cast<string> (stu.m_number);
				string inedex = to_string(stu.m_number);//���ַ���������
				return inedex == str;

			});
		vec_stu.erase(it, vec_stu.end());
		m_showTable->clear();
		updateShowTable();
		this->saveFile("images/xscj.txt"); 
		cout << "\a";


		string tisici = "ɾ���ɹ�";
		settextcolor(RED);
		settextstyle(46, 0, "����");
		outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
		settextstyle(24, 0, "����");
		settextcolor(BLACK);
		Window::flushDraw();//�ͷŻ�����
		Sleep(2000);
		m_delTable->clear();//�������ɾ��

	}

	//outtextxy(0, 0, "erase");
	//cout << "erase" << endl;
}

void Management::modify()
{

	const char* title = "��������Ҫ�޸ĵ�ѧ����ѧ��";
	settextstyle(36, 0, "����");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2 - 100, title);
	settextstyle(24, 0, "����");


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
			string tisici1 = "�Բ���û���ҵ�ѧ��Ϊ";
			string tisici2 = "��ѧ��";
			string tisici = tisici1 + str + tisici2;
			settextcolor(RED);
			settextstyle(46, 0, "����");
			outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
			settextstyle(24, 0, "����");
			settextcolor(BLACK);
			Window::flushDraw();//�ͷŻ�����
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
					//m_modifyIt->m_number = atoi(m_stuEdit[i]->text().c_str());//��c�����ַ���ת��Ϊ��ֵ����--��ͷ�ļ�cstdlib����
					//m_modifyIt->m_number = stoi(m_stuEdit[i]->text());//��c�����ַ���ת��Ϊ��ֵ���ͣ�������--c++11֮��ʹ��stoi()�ṩ�쳣���������ƿռ�std��,�����Խ���string�����ַ���,����ֵ��int
					//��Ҫת���������ֵ��������int��Χ�ڵ�ֵ��������stol()����stoll(),����ֵ��long,long long 
					m_modifyIt->m_number = stoll(m_stuEdit[i]->text());

					//cout << m_modifyIt->m_number << endl;
					
					tisici = "�޸�ѧ�ųɹ�";						
										
				}
					break;
				case 1:
				{
					m_modifyIt->m_name = m_stuEdit[i]->text();

					tisici = "�޸������ɹ�";
											
				}
					break;
				case 2:
				{
					m_modifyIt->m_grade = m_stuEdit[i]->text();

					tisici = "�޸İ༶�ɹ�";
										
				}
					break;
				case 3:
				{
					m_modifyIt->m_math = stoll(m_stuEdit[i]->text());


					tisici = "�޸���ѧ�ɼ��ɹ�";										
				}
					break;
				case 4:
				{
					m_modifyIt->m_chinese = stoll(m_stuEdit[i]->text());


					tisici = "�޸����ĳɼ��ɹ�";
										
				}
					break;
				case 5:
				{
					m_modifyIt->m_english = stoll(m_stuEdit[i]->text());

						
					tisici = "�޸�Ӣ��ɼ��ɹ�";
									
				}
					break;
				
				}
				m_showTable->clear();//�����ԭʼ������ݽ������
				updateShowTable();
				this->saveFile("images/xscj.txt");

				cout << "\a";
				settextcolor(RED);
				settextstyle(46, 0, "����");
				outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
				settextstyle(24, 0, "����");
				settextcolor(BLACK);
				Window::flushDraw();//�ͷŻ�����
				Sleep(2000);

				

				
			}

		}


	}

	//outtextxy(0, 0, "modify");
	//cout << "modify" << endl;
}

void Management::search()
{

	const char* title = "��������Ҫ���ҵ�ѧ����ѧ��";
	settextstyle(36, 0, "����");
	outtextxy((Window::width() - textwidth(title)) / 2, (Window::height() - textheight(title)) / 2, title);
	settextstyle(24, 0, "����");


	m_serchBtn->show();
	m_serchEdit->show();

	if (m_serchTable->rowCount() != 0)//�����������
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
				string inedex = to_string(stu.m_number);//���ַ���������
				return inedex == str;

			});

		if (it == vec_stu.end())
		{
			cout << "\a";
			string tisici1 = "�Բ���û���ҵ�ѧ��Ϊ";
			string tisici2 = "��ѧ��";
			string tisici = tisici1 + str + tisici2;
			settextcolor(RED);
			settextstyle(46, 0, "����");
			outtextxy((Window::width() - textwidth(tisici.c_str())) / 2, (Window::height() - textheight(tisici.c_str())) / 2 + 300, tisici.c_str());
			settextstyle(24, 0, "����");
			settextcolor(BLACK);
			Window::flushDraw();//�ͷŻ�����
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
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	getline(read, m_header);//��ȡ��ͷ
	//std::cout << m_header << endl;


	while (!read.eof())//��ȡ�������
	{
		std::string index = "1";
		getline(read, index);
		if (strlen(index.c_str()) == 0)//��ȡ�������н�����ȡ
		{
			break;
		}

		Student stu;
		stringstream ss(index);//��ʽ��д��
		ss >> stu.m_number >> stu.m_name >> stu.m_grade >> stu.m_math >> stu.m_chinese >> stu.m_english;

		vec_stu.push_back(stu);
		//cout << stu.m_number << stu.m_name << stu.m_grade << stu.m_math << stu.m_chinese << stu.m_english << endl;


	}

	read.close();

}



void Management::saveFile(const std::string& fileName)
{
	ofstream fout;
	fout.open(fileName, ios_base::out | ios_base::trunc);//����ļ�������ض��ļ�ios_base::app����׷��д��
	if (!fout.is_open())
	{
		cerr << "�ļ���ʧ��" << endl;
		return;

	}

	//m_header += "\n";//�������������������ֿ��У����¶�ȡ�ļ����ݵ�����ʱ���������жϣ��޷���ȡ�ļ��е����ݵ�����
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