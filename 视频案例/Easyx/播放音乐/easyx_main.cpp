#include<easyx.h>
#include<Windows.h>
#include<mmsystem.h>
#include<string>
#include<iostream>

using namespace std;

#pragma comment(lib, "winmm.lib")




int main()
{
	//mciSendString("open assets/aq.mp3", nullptr, 0, nullptr);//��������
	//mciSendString("play assets/aq.mp3", nullptr, 0, nullptr);//��������


	
	mciSendString("open assets/aq.mp3 alias bgm", nullptr, 0, nullptr);//��������----��������
	mciSendString("play bgm", nullptr, 0, nullptr);//��������
	MCIERROR ret = mciSendString("setaudio bgm volume to 10", nullptr, 0, nullptr);//��������---������Χ0-1000



	//��ȡ������Ϣ
	if (ret != 0)
	{
		char err[100] = { 0 };
		mciGetErrorString(ret, err, sizeof(err));
		cout << err << endl;

	}





	

	system("pause");
	return 0;
}


