#include "Table.h"

Table::Table(int row, int col)
	:BasicWidget(0, 0, 0, 0),m_row(row),m_col(col),m_curPage(0),m_maxPage(0),m_extraData(0),m_cckzf(0)
{
	m_prevBtn = new PushButton("��һҳ");
	m_nextBtn = new PushButton("��һҳ");
	m_firstBtn = new PushButton("��һҳ");
	m_lastBtn = new PushButton("��βҳ");
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
	m_col = std::count(m_header.begin(), m_header.end(), '\t') + 1;//���ñ�ͷȷ�����������

	m_tw = textwidth("�����1401");
	m_th = textheight(m_header.c_str());

	m_gridW = m_tw + 16;//�������ֵĿ�Ⱥ͸߶�ȷ�������ӵĸ߶ȺͿ��
	m_gridH = m_th + 16;

	m_h = m_row * m_gridH;//���ñ��������͸��Ӹ߶ȵó����ĸ߶�
	m_w = m_col * m_gridW;//���ø��ӵĿ�������ó����Ŀ��

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
	rectangle(m_x, m_y - m_gridH, m_x + m_w, m_y);//��һ���߿����
	for (int i = 0; i < m_col; i++)//������
	{

		line(m_x + i * m_gridW, m_y - m_gridH, m_x + i * m_gridW, m_y);

	}
	setlinestyle(PS_SOLID, 1);

	//�ָ�ͷ������
	auto headers = split(m_header, '\t');

	for (int i = 0; i < headers.size(); i++)
	{

		int txspe = (m_gridW - textwidth(headers[i].c_str())) / 2;//�������־���
		int tyspe = (m_gridH - textheight(headers[i].c_str())) / 2;

		outtextxy(m_x + i * m_gridW + txspe, m_y - m_gridH + tyspe, headers[i].c_str());

	}


}



void Table::drawTalbeGrid()//���Ʊ�����
{
	//������
	setlinecolor(BLACK);
	for (int i = 0; i < m_row + 1; i++)
	{
		line(m_x, m_y + i * m_gridH, m_x + m_col * m_gridW, m_y + i * m_gridH);

	}
	//������
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

	//"��1ҳ/��7ҳ"

	std::string str1 = "��";
	std::string str2 = boost::lexical_cast<std::string> (m_curPage + 1);
	std::string str3 = "ҳ/��";
	std::string str4 = boost::lexical_cast<std::string> (m_maxPage + 1);
	std::string str5 = "ҳ";
	std::string str = str1 + str2 + str3 + str4 + str5;


	outtextxy(m_lastBtn->x() + m_lastBtn->width() + 250, m_lastBtn->y(), str.c_str());

}


void Table::drawTalbeData()//���Ʊ�����ݲ���
{
	if (m_datas.size() == 0)
	{
		return;
	}

	//��ֹԽ��
	if (m_row > m_datas.size() && m_datas.size() != 0)
	{
		m_row = m_datas.size();
	}

	//ɾ��ѧ��ʱ�õ�
	if (m_row == 0 && !m_datas.empty())
	{
		m_row = m_datas.size();
	}


	
		

	int begPos = m_curPage * m_row;
	int endPos = begPos + m_row;
	//��������һҳ��ֻ����ʣ�������

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
			int tx = m_x + k * m_gridW + (m_gridW - textwidth(line_data[k].c_str())) / 2;//�������־���
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


std::vector<std::string> Table::split(std::string str, char separator)//�����ڵ���ʱ�������ܰ����ô��ݣ��´η��ʵ�ʱ���Ѿ��ͷ����ڴ�
{
	std::vector<std::string> res;

	for (int i = 0; i != std::string::npos;)
	{
		i = str.find(separator);//����ĳһ���ַ����ַ����е��±�λ��
		res.push_back(str.substr(0, i));//�����ַ������±귶Χ�ڵ��ַ����Ӵ�
		str = std::string(str.c_str() + i + 1);

	}
	return res;

}


void Table::updatePage()
{
	//ɾ��ѧ��ʱ�õ�
	if (m_row == 0 && !m_datas.empty())
	{
		m_row = m_datas.size();
	}

	//if (m_col == 0 && !m_datas.empty())
	//{
	//	m_col = m_datas.front().find('\t') + 1;//�����������Ǵ����
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
			m_maxPage = m_datas.size() / m_row - 1;//���������жϵĻ�����������ʱ�����һ����ҳ
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