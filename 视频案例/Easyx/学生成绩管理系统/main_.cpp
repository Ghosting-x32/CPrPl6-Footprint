#include<iostream>
#include<easyx.h>
#include<Windows.h>

#include"Management.h"
#include"Window.h"


using namespace std;

int main()
{
	//Window w1(1280, 720, EX_SHOWCONSOLE);
	Window w1(1280, 720);//��������֮��������ʾ������ֻ�ǳ�������ʱ��С��
	//������ʾ�������ʾ������Ҫ��������

	  // ���ؿ���̨����
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);//����1---��������֮��������ʾ������ֻ�ǳ�������ʱ��С��

	//����2-----����֮��ֻ������취����
	/*
1.�޸���ڵ㣺

����Ŀ�����У��ҵ�"������" -> "�߼�"

��"��ڵ�"����ΪmainCRTStartup


	
	*/
	w1.setWindowTitle("�ߵ�ѧ���ɼ�����ϵͳ");


	Management ma1;
	ma1.run();




	system("pause");
	return 0;
}