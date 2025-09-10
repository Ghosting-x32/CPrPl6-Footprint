#include<easyx.h>
#include<Windows.h>
#include<mmsystem.h>
#include<string>
#include<iostream>

using namespace std;

#pragma comment(lib, "winmm.lib")




int main()
{
	//mciSendString("open assets/aq.mp3", nullptr, 0, nullptr);//加载音乐
	//mciSendString("play assets/aq.mp3", nullptr, 0, nullptr);//播放音乐


	
	mciSendString("open assets/aq.mp3 alias bgm", nullptr, 0, nullptr);//加载音乐----别名播放
	mciSendString("play bgm", nullptr, 0, nullptr);//播放音乐
	MCIERROR ret = mciSendString("setaudio bgm volume to 10", nullptr, 0, nullptr);//调整音量---音量范围0-1000



	//获取错误信息
	if (ret != 0)
	{
		char err[100] = { 0 };
		mciGetErrorString(ret, err, sizeof(err));
		cout << err << endl;

	}





	

	system("pause");
	return 0;
}


