#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	

	long val = 560031841;//00100001 01100001 01101000 01100001
	//                       !          a        h        a
	cout << &val << endl;//000000360258FB14--16����ÿһ�����ж���ͬ
	cout << (char*)&val << endl;
	cout.write((char*)&val, sizeof(long)) << endl;
	//�����ڴ��д����λ��ʾ
	//ʮ����ǿ��ת��Ϊ�����Ƶ�ַ--��������Ʊ�ʾ���ַ�����¼C ASCII �ַ�����


	system("pause");
	return 0;
}