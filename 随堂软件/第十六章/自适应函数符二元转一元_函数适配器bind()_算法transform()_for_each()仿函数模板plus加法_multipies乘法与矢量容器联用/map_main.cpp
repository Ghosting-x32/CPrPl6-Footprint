#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>//�º���ģ����ͷ�ļ�


using namespace std;

void Show(double v);
const int LIM = 6;



int main()
{
	double arr1[LIM] = { 28, 29, 30, 35, 38, 59 };
	double arr2[LIM] = { 63, 65, 69, 75, 80, 99 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);

	cout.setf(ios_base::fixed);
	cout.precision(2);//����cout�����ʾ��С��λ��
	cout << "gr8:\t";
	for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	//double a = 20;
	//double b = 30;
	//double c = 50;

	////cout.setf(ios_base::fixed);
	//cout.precision(4);//����cout�����ʾ��С��λ��
	//cout << endl << a;
	//cout.width(10);
	//cout << b;
	//cout.width(10);
	//cout << c << endl;

	cout << "\nm8: \t";
	for_each(m8.begin(), m8.end(), Show);
	cout << endl;

	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());//ʹ�üӷ��º���ģ��
	//������ʸ��������Ԫ�ض�Ӧ���ӷ�
	cout << "\nsum:\t";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;


	vector<double> prod(LIM);
	//transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));//bind1st()��c++17��׼�б��Ƴ�
	transform(gr8.begin(), gr8.end(), prod.begin(), bind(multiplies<double>(), placeholders::_1, 2.5));//Ӧʹ��bind(),placeholders::_1����ռλ��--����1

	//���ú�����ǩ������funx111���β����ͺͷ���ֵ����---����2
	//function<double(double)> funx111 = bind(multiplies<double>(), placeholders::_1, 2.5);//����2-1
	//auto funx111 = bind(multiplies<double>(), placeholders::_1, 2.5);//����2-2---�Զ������Ƶ�
	//transform(gr8.begin(), gr8.end(), prod.begin(), funx111);//Ӧʹ��bind(),placeholders::_1����ռλ��
	//cout << "hhh" << endl << endl << funx111(10) << endl;//���Ժ���funx111()

	cout << "\nprod:\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;
















	system("pause");
	return 0;
}


void Show(double v)
{
	cout.width(8);//����cout�����ʾ�Ŀ��
	cout << v << " ";
}