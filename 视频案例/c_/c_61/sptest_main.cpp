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
	ofstream ofs1;//2.创建一个写入对象
	ofs1.open("sptest.txt", ios::out);//3.打开文件：写入对象.open("文件路径", 打开方式)
	ofs1 << "姓名： 张三" << endl;//4.写入数据
	ofs1 << "性别： 男" << endl;
	ofs1 << "年龄： 35" << endl;
	ofs1.close();//5.关闭文件
}


