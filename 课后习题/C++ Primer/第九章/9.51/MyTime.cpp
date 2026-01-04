#include "MyTime.h"


MyTime::MyTime(const string& str)
{
	vector<string> mouns;
	mouns.resize(25);
	mouns[0] = "January";
	mouns[1] = "February";
	mouns[2] = "March";
	mouns[3] = "April";
	mouns[4] = "May";
	mouns[5] = "June";
	mouns[6] = "July";
	mouns[7] = "August";
	mouns[8] = "September";
	mouns[9] = "October";
	mouns[10] = "November";
	mouns[11] = "December";
	mouns[12] = "Jan";
	mouns[13] = "Feb";
	mouns[14] = "Mar";
	mouns[15] = "Apr";
	mouns[16] = "May";
	mouns[17] = "Jun";
	mouns[18] = "Jul";
	mouns[19] = "Aug";
	mouns[20] = "Sep";//9月
	mouns[21] = "Sept";//9月
	mouns[22] = "Sept";
	mouns[23] = "Nov";
	mouns[24] = "Dec";

	string str_abc("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string str_123("0123456789");
	string str_year_n;
	string str_moun_n;
	string str_day_n;
	string str_day_year;
	string str_moun_year;


	year_n = 0;
	moun_n = 0;
	day_n = 0;

	string::size_type pos_abc = 0;
	if ((pos_abc = str.find_first_of(str_abc, pos_abc)) != string::npos)
	{
		string::size_type pos = 0;
		bool temp = false;
		for (string::size_type i = 0; i < 25; ++i)
		{

			if ((pos = str.find(mouns[i])) != string::npos && temp == false)//
			{
				//cout << " hhh" << endl;
				if (i > 11)
				{
					moun_n = i - 12 + 1;
					temp = true;
				}
				else
				{
					moun_n = i + 1;
					temp = true;

				}




			}

		}
		//cout << moun_n << endl;
		//system("pause");



		for (string::size_type i = 0; i < str.size(); ++i)
		{
			if (isdigit(str[i]))
			{
				str_day_year += str[i];
			}


		}

		if (str_day_year.size() == 5)
		{
			str_day_n.assign(str_day_year.begin(), str_day_year.begin() + 1);
			str_year_n.assign(str_day_year.begin() + 1, str_day_year.end());


		}
		else
		{
			str_day_n.assign(str_day_year.begin(), str_day_year.begin() + 2);
			str_year_n.assign(str_day_year.begin() + 2, str_day_year.end());
		}

		day_n = std::stoi(str_day_n);

		year_n = std::stoi(str_year_n);


	}
	else
	{
		string::size_type pos = 0;//此处不该查找字符，而是应该查找第一个不是数字的下标使用str_123,配合find_first_not_of(str_123, pos);
		//这样不管是什么字符分隔都能处理
		pos = str.find_first_of('/', pos);//28/11/1990
		str_day_n.assign(str.begin(), str.begin() + pos);
		str_moun_year.assign(str.begin() + pos + 1, str.end());
		string::size_type pos_my = 0;
		pos_my = str_moun_year.find_first_of('/', pos_my);
		str_moun_n.assign(str_moun_year.begin(), str_moun_year.begin() + pos_my);
		str_year_n.assign(str_moun_year.begin() + pos_my + 1, str_moun_year.end());
		//cout << str_day_n << endl;
		//cout << str_moun_n << endl;
		//cout << str_year_n << endl;
		//system("pause");
		day_n = std::stoi(str_day_n);
		moun_n = std::stoi(str_moun_n);
		year_n = std::stoi(str_year_n);

		//cout << str_day_n << endl;
		//system("pause");


	}






}



void MyTime::print()
{
	cout << year_n << "年" << moun_n << "月" << day_n << "日" << endl;
}