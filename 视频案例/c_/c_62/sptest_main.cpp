#include<iostream>
#include<string>
#include<fstream>//1.包含头文件<fstream>


using namespace std;
void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	ifstream ifs1;//2.创建一个读取对象
	ifs1.open("sptest.txt", ios::out);//3.打开文件：读取对象.open("文件路径", 打开方式)
	if (!ifs1.is_open())//判断文件是否打开成功
	{
		cout << "文件打开失败！" << endl;
	}
	//4.读取数据
	//4.1直接读取,使用char数组存储，不是面向行，遇到空字符也执行循环，导致遇到空字符就换行
	/*
	char buf1[1024] = {0};
	while (ifs1 >> buf1)
	{
		cout << buf1 << endl;
	}
	*/

	//4.2直接读取,使用string对象存储,不是面向行，遇到空字符也执行循环，导致遇到空字符就换行
	/*
		string buf3;
	while (ifs1 >> buf3)
	{
		cout << buf3 << endl;
	}
	*/

	

	//4.3面向行的读取，使用char数组存储
	/*
	char buf[1024] = { 0 };
	while (ifs1.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	*/
	
	//4.4面向行的读取，使用string对象储存
	
	string buf2;
	while (getline(ifs1, buf2))
	{
	cout << buf2 << endl; 
	}
	
	
	//4.5不是面向行，遇到空字符也执行循环，导致遇到空字符就换行,get()一个字符一个字符读取
	//效率太低，不建议使用
	/*
	char buf4;
	while ((buf4 = ifs1.get()) != EOF)//遇到文件尾结束循环
	{
		cout << buf4;
	}
	*/



	
	ifs1.close();//5.关闭文件
}


