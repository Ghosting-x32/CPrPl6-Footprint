#include<iostream>
#include<string>
#include<stdexcept>
#include<typeinfo>

#include"Sales.h"
#include"LabeledSales.h"

using namespace std;

int main()
{

	double vals1[12]
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12]
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);


	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales1[i] << " ";
			if (i % 6 == 5)
			{
				cout << endl;
			}

		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; i++)
		{
			cout << sales2[i] << " ";//i等于12的时候抛出异常----nbad_index类型异常
			if (i % 6 == 5)
			{
				cout << endl;
			}

		}
		cout << "End of try block 1.\n";



	}

	/*catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;

	}*/

	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
		try
		{
			LabeledSales::nbad_index& ps = dynamic_cast<LabeledSales::nbad_index&>(bad);//#1  dynamic_cast用作引用的时候
			//如果bad引用不能赋值给ps引用（LabeledSales::nbad_index&类型引用）则会抛出bad_cast类型的异常
			// 如果bad引用能赋值给ps引用（LabeledSales::nbad_index&类型引用）则ps = bad;
			//该异常在头文件<typeinfo>，是从exception类派生的
			cout << "Company: " << ps.label_val() << endl;
			cout << "捕获到子类的异常并处理！" << endl;
		}
		catch(bad_cast& s1)//捕获#1抛出的异常
		{
			cout << "捕获到父类的异常并处理！" << endl;
		}	

	}



	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;//抛出异常---bad_index类型的异常
		cout << "End of try block 2.\n";

	}
	/*catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;

	}*/

	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
		try
		{
			LabeledSales::nbad_index& ps = dynamic_cast<LabeledSales::nbad_index&>(bad);
			cout << "Company: " << ps.label_val() << endl;
			cout << "捕获到子类的异常并处理！" << endl;
		}
		catch (bad_cast& s1)
		{
			cout << "捕获到父类的异常并处理！" << endl;
		}

	}



	system("pause");
	return 0;
}