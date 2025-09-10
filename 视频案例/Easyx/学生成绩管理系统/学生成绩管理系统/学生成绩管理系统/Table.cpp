#include "Table.h"

Table::Table(int row, int col)
	:BasicWidget(0, 0, 0, 0),m_row(row),m_col(col),m_curPage(0),m_maxPage(0),m_extraData(0),m_cckzf(0)
{
	m_prevBtn = new PushButton("上一页");
	m_nextBtn = new PushButton("下一页");
	m_firstBtn = new PushButton("第一页");
	m_lastBtn = new PushButton("结尾页");
}


Table::~Table()
{
	if (m_prevBtn != nullptr)
	{
		delete m_prevBtn;
		m_prevBtn = nullptr;
	}

	if (m_nextBtn != nullptr)
	{
		delete m_nextBtn;
		m_nextBtn = nullptr;
	}

	if (m_firstBtn != nullptr)
	{
		delete m_firstBtn;
		m_firstBtn = nullptr;
	}

	if (m_lastBtn != nullptr)
	{
		delete m_lastBtn;
		m_lastBtn = nullptr;
	}

}


void Table::setRowCount(int row)
{
	m_row = row;

}


void Table::setColCount(int col)
{
	m_col = col;

}

void Table::setHeader(const std::string& header)
{
	m_header = header;
	m_col = std::count(m_header.begin(), m_header.end(), '\t') + 1;//利用表头确定出表格列数

	m_tw = textwidth("计算机1401");
	m_th = textheight(m_header.c_str());

	m_gridW = m_tw + 16;//利用文字的宽度和高度确定出格子的高度和宽度
	m_gridH = m_th + 16;

	m_h = m_row * m_gridH;//利用表格的行数和格子高度得出表格的高度
	m_w = m_col * m_gridW;//利用格子的宽度列数得出表格的宽度

}





void Table::show()
{

	drawTalbeGrid();
	drawHeader();
	drawTalbeData();
	//Window::flushDraw();
	//system("pause");
}

void Table::drawHeader()
{
	setlinestyle(PS_SOLID, 2);
	rectangle(m_x, m_y - m_gridH, m_x + m_w, m_y);//画一个边框矩形
	for (int i = 0; i < m_col; i++)//画竖线
	{

		line(m_x + i * m_gridW, m_y - m_gridH, m_x + i * m_gridW, m_y);

	}
	setlinestyle(PS_SOLID, 1);

	//分割头部数据
	auto headers = split(m_header, '\t');

	for (int i = 0; i < headers.size(); i++)
	{

		int txspe = (m_gridW - textwidth(headers[i].c_str())) / 2;//设置文字居中
		int tyspe = (m_gridH - textheight(headers[i].c_str())) / 2;

		outtextxy(m_x + i * m_gridW + txspe, m_y - m_gridH + tyspe, headers[i].c_str());

	}


}



void Table::drawTalbeGrid()//绘制表格外观
{
	//画横线
	setlinecolor(BLACK);
	for (int i = 0; i < m_row + 1; i++)
	{
		line(m_x, m_y + i * m_gridH, m_x + m_col * m_gridW, m_y + i * m_gridH);

	}
	//画竖线
	for (int i = 0; i < m_col + 1; i++)
	{
		line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_row * m_gridH);
	}


	if (m_maxPage > 0 && m_cckzf == 0)
	{
		drawButton();
	}



}



void Table::event()
{
	BasicWidget::event();


	m_prevBtn->event();
	m_nextBtn->event();
	m_firstBtn->event();
	m_lastBtn->event();

	if (m_prevBtn->isClicked())
	{
		if (m_curPage != 0)
		{
			m_curPage--;

		}

	}

	if (m_nextBtn->isClicked())
	{
		if (m_curPage != m_maxPage)
		{
			m_curPage++;
		}

	}

	if (m_firstBtn->isClicked())
	{
		m_curPage = 0;

	}

	if (m_lastBtn->isClicked())
	{
		m_curPage = m_maxPage;

	}


}


void Table::drawButton()
{
	int jiage = 10;
	m_prevBtn->move(m_x, m_h + 120);
	m_nextBtn->move(m_prevBtn->x() + m_prevBtn->width() + jiage, m_prevBtn->y());
	m_firstBtn->move(m_nextBtn->x() + m_nextBtn->width() + jiage, m_prevBtn->y());
	m_lastBtn->move(m_firstBtn->x() + m_firstBtn->width() + jiage, m_prevBtn->y());

	m_prevBtn->show();
	m_nextBtn->show();
	m_firstBtn->show();
	m_lastBtn->show();

	//"第1页/共7页"

	std::string str1 = "第";
	std::string str2 = boost::lexical_cast<std::string> (m_curPage + 1);
	std::string str3 = "页/共";
	std::string str4 = boost::lexical_cast<std::string> (m_maxPage + 1);
	std::string str5 = "页";
	std::string str = str1 + str2 + str3 + str4 + str5;


	outtextxy(m_lastBtn->x() + m_lastBtn->width() + 250, m_lastBtn->y(), str.c_str());

}


void Table::drawTalbeData()//绘制表格数据部分
{
	if (m_datas.size() == 0)
	{
		return;
	}

	//防止越界
	if (m_row > m_datas.size() && m_datas.size() != 0)
	{
		m_row = m_datas.size();
	}

	//删除学生时用到
	if (m_row == 0 && !m_datas.empty())
	{
		m_row = m_datas.size();
	}


	
		

	int begPos = m_curPage * m_row;
	int endPos = begPos + m_row;
	//如果是最后一页，只遍历剩余的数据

	if (m_curPage == m_maxPage)
	{
		if (m_datas.size() % m_row == 0)
		{
			endPos = begPos + m_row;
		}
		else
		{
			endPos = begPos + m_extraData;
		}

	}


	
	for (int i = begPos, r = 0; i < endPos; i++, r++)
	{
		auto line_data = split(m_datas[i], '\t');

		for (int k = 0; k < line_data.size(); k++)
		{
			int tx = m_x + k * m_gridW + (m_gridW - textwidth(line_data[k].c_str())) / 2;//调整文字居中
			int ty = m_y + r * m_gridH + 8;

			settextcolor(BLACK);
			outtextxy(tx, ty, line_data[k].c_str());


		}

	}


}

void Table::insertData(const std::string& data)
{
	m_datas.push_back(data);
	updatePage();
}


std::vector<std::string> Table::split(std::string str, char separator)//函数内的临时变量不能按引用传递，下次访问的时候已经释放了内存
{
	std::vector<std::string> res;

	for (int i = 0; i != std::string::npos;)
	{
		i = str.find(separator);//查找某一个字符在字符串中的下标位置
		res.push_back(str.substr(0, i));//返回字符串中下标范围内的字符串子串
		str = std::string(str.c_str() + i + 1);

	}
	return res;

}


void Table::updatePage()
{
	//删除学生时用到
	if (m_row == 0 && !m_datas.empty())
	{
		m_row = m_datas.size();
	}

	//if (m_col == 0 && !m_datas.empty())
	//{
	//	m_col = m_datas.front().find('\t') + 1;//这样算列数是错误的
	//}
	//--------------------------------



	if (m_row >= m_datas.size())
	{
		m_maxPage = 0;
		m_extraData = m_datas.size();

	}
	else
	{

		if (m_datas.size() % m_row == 0)
		{
			m_maxPage = m_datas.size() / m_row - 1;//不做整除判断的话，被整除的时候会有一个空页
			m_extraData = m_datas.size() % m_row;
		}
		else
		{
			m_maxPage = m_datas.size() / m_row;

			m_extraData = m_datas.size() % m_row;
		}
		
	}

}


int Table::rowCount()
{

	return this->m_row;

}


int Table::colCount()
{

	return this->m_col;

}

void Table::clear()
{

	m_datas.clear();
}


void Table::eraseDY()
{
	if (m_datas.size() > 1)
	{
		m_datas.erase(m_datas.begin());
	}

}


int Table::sizeCZ()
{
	return m_datas.size();

}


void Table::updat_cckzf(int cckzf)
{
	m_cckzf = cckzf;

}