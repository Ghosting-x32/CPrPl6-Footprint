#include"OrderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs1;
	ifs1.open(ORDER_FILE, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "文件打开失败！" << endl;
		ifs1.close();
		system("pause");
		system("cls");
		return;
	}

	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "文件数据为空！" << endl;
		ifs1.close();
		system("pause");
		system("cls");
		return;
	}
	ifs1.putback(ch);

	string date;//日期
	string interval;//时间段
	string stuId;//学生学号
	string stuName;//学生姓名
	string room;//机房编号
	string status;//预约状态

	this->m_Size = 0;//初始化预约条数为1

	while (ifs1 >> date && ifs1 >> interval && ifs1 >> stuId && ifs1 >> stuName && ifs1 >> room && ifs1 >> status)//解析文件中的数据，储存到容器中
	{
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");//date:111   8-4-1
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(pair<string, string>(key, value));
		}
		
		pos = interval.find(":");//date:111   8-4-1
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(pair<string, string>(key, value));
		}

		pos = stuId.find(":");//date:111   8-4-1
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(pair<string, string>(key, value));
		}

		pos = stuName.find(":");//date:111   8-4-1
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(pair<string, string>(key, value));
		}

		pos = room.find(":");//date:111   8-4-1
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(pair<string, string>(key, value));
		}

		pos = status.find(":");//date:111   8-4-1
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(pair<string, string>(key, value));
		}
		this->m_orderData.insert(pair<int, map<string, string>>(this->m_Size, m));
		this->m_Size++;
	}

	ifs1.close();
	/*for (map<int, map<string, string>>::iterator it = this->m_orderData.begin(); it != this->m_orderData.end(); it++)
	{
		cout << "条数为：" << it->first + 1 << " value = " << endl;
		for (map<string, string>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++)
		{
			cout << " key = " << it1->first << " value = " << it1->second << " ";

		}
		
		cout << endl;
		cout << it->second.size() << endl;
	}*/




}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs1;
	ofs1.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs1 << "date:" << this->m_orderData[i]["date"] << " "
			<< "interval:" << this->m_orderData[i]["interval"] << " "
			<< "stuId:" << this->m_orderData[i]["stuId"] << " "
			<< "stuName:" << this->m_orderData[i]["stuName"] << " "
			<< "roomId:" << this->m_orderData[i]["roomId"] << " "
			<< "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs1.close();

}