#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>//仿函数模板类头文件


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
	cout.precision(2);//调整cout输出显示的小数位数
	cout << "gr8:\t";
	for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	//double a = 20;
	//double b = 30;
	//double c = 50;

	////cout.setf(ios_base::fixed);
	//cout.precision(4);//调整cout输出显示的小数位数
	//cout << endl << a;
	//cout.width(10);
	//cout << b;
	//cout.width(10);
	//cout << c << endl;

	cout << "\nm8: \t";
	for_each(m8.begin(), m8.end(), Show);
	cout << endl;

	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());//使用加法仿函数模板
	//将两个矢量容器的元素对应做加法
	cout << "\nsum:\t";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;


	vector<double> prod(LIM);
	//transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));//bind1st()在c++17标准中被移除
	transform(gr8.begin(), gr8.end(), prod.begin(), bind(multiplies<double>(), placeholders::_1, 2.5));//应使用bind(),placeholders::_1参数占位符--方法1

	//设置函数标签，表明funx111的形参类型和返回值类型---方法2
	//function<double(double)> funx111 = bind(multiplies<double>(), placeholders::_1, 2.5);//方法2-1
	//auto funx111 = bind(multiplies<double>(), placeholders::_1, 2.5);//方法2-2---自动类型推导
	//transform(gr8.begin(), gr8.end(), prod.begin(), funx111);//应使用bind(),placeholders::_1参数占位符
	//cout << "hhh" << endl << endl << funx111(10) << endl;//测试函数funx111()

	cout << "\nprod:\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;
















	system("pause");
	return 0;
}


void Show(double v)
{
	cout.width(8);//调整cout输出显示的宽度
	cout << v << " ";
}