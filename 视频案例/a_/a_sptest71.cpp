#include<iostream>
#include<string>
using namespace std;

//1.创建一个英雄的结构
struct Hero
{
	string name;
	int age;
	string sex;
};

void bubbleSort(Hero heroArray[], int len);
void printHero(Hero heroArray[], int len);

int main()
{
	
	//2.创建一个英雄结构数组
	Hero heroArray[5] =
	{
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "排序前英雄结构数组的内容：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "英雄名字：" << heroArray[i].name << " 英雄的年龄：" << heroArray[i].age << " 英雄的性别：" << heroArray[i].sex << endl;
	}
	//3.对英雄结构数组进行冒泡排序
	bubbleSort(heroArray, len);
	//4.对英雄结构数组内容进行打印
	cout << "排序后英雄结构数组的内容：" << endl;
	printHero(heroArray, len);

	

	system("pause");
	return 0;
}

void bubbleSort(Hero heroArray[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heroArray[j].age > heroArray[j + 1].age)
			{
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

void printHero(Hero heroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "英雄名字：" << heroArray[i].name << " 英雄的年龄：" << heroArray[i].age << " 英雄的性别：" << heroArray[i].sex << endl;
	}
}