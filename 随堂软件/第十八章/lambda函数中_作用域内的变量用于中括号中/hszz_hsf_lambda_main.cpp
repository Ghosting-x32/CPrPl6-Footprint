#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<cmath>
#include<ctime>
#include<chrono>


using namespace std;
const long Size1 = 390000L;


void showint(int n);



int main()
{
	auto time_seed = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��
	random_device(rd);
	mt19937 gen(rd() ^ time_seed);

	vector<int> number(Size1);
	generate(number.begin(), number.end(), gen);
	int temp = number.back();
	int temp1 = number.front();



	cout << "Sample size = " << Size1 << endl;

	int count3 = count_if(number.begin(), number.end(), [](int n) {return n % 3 == 0; });	
	cout << "Count of numbers divisible by 3: " << count3 << endl;

	int count13 = 0;
	for_each(number.begin(), number.end(), [&count13](int n) {count13 += n % 13 == 0; });//lambda�����У��������ڵĵ������������ñ�������������
	cout << "Count of numbers divisible by 13: " << count13 << endl;


	auto time_seed1 = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//��ȡ�߾���ʱ�����΢�뼶��
	mt19937 gen1(rd() ^ time_seed1);//ˢ��ϵͳʱ�������һ����ʱ�����ɲ�һ�������number,ʹ��number��������ݲ�һ��


	count3 = count13 = 0;
	vector<int> number1(Size1);
	generate(number1.begin(), number1.end(), gen1);

	int temp2 = number1.back();
	int temp3 = number1.front();

	for_each(number1.begin(), number1.end(), [&](int n) {count3 += n % 3 == 0; count13 += n % 13 == 0; });//lambda�����У��������ڵ����б��������ñ�������������
	cout << "Count of numbers divisible by 3: " << count3 << endl;
	cout << "Count of numbers divisible by 13: " << count13 << endl;



	cout << temp1 << endl << temp << endl << endl << temp3 << endl << temp2 << endl;//��֤����number��vector���󣩵�ͷ��β����һ��



	system("pause");
	return 0;
}

void showint(int n)
{
	cout << n << endl;
}
