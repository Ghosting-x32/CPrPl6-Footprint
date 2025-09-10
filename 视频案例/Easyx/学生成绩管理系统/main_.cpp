#include<iostream>
#include<easyx.h>
#include<Windows.h>

#include"Management.h"
#include"Window.h"


using namespace std;

int main()
{
	//Window w1(1280, 720, EX_SHOWCONSOLE);
	Window w1(1280, 720);//这样设置之后命令提示符窗口只是程序运行时最小化
	//不想显示命令符提示窗口需要这样设置

	  // 隐藏控制台窗口
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);//方法1---这样设置之后命令提示符窗口只是程序运行时最小化

	//方法2-----测试之后只有这个办法有用
	/*
1.修改入口点：

在项目属性中，找到"链接器" -> "高级"

将"入口点"设置为mainCRTStartup


	
	*/
	w1.setWindowTitle("高等学生成绩管理系统");


	Management ma1;
	ma1.run();




	system("pause");
	return 0;
}