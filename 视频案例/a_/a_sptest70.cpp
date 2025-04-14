#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Student {
	string sName;
	int score;
};

struct Teacher {
	string tName;
	Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len);//给老师数组赋值
void printInfo(Teacher tArray[], int len);//打印老师数组内容

int main()
{
	srand((unsigned int)time(NULL));//提供一个随机数种子，使系统按时间随机生成数字
	Teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);
	printInfo(tArray, len);

	

	system("pause");
	return 0;
}

void allocateSpace(Teacher tArray[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];
		for (int j = 0; j < 5; j++)//给学生数组赋值
		{
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];
			int random = rand() % 61 + 40;//生成40~100的随机数
			tArray[i].sArray[j].score = random;
		}
	}
}

void printInfo(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "教师名字：" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t" //学生内容打印的时候插入一个水平制表符，显示更清晰。
				 << "学生名字：" << tArray[i].sArray[j].sName << " 学生分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}