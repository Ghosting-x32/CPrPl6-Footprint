#include <iostream>//for循环将数字递减
int main()
{
	using namespace std;
	cout << "Enter the starting coutdown value: ";
	int limit;
	cin >> limit;
	int i;
	for (i = limit; i; i--)//C++语言中,凡是 “表达式=0”的判断,都可以省略判断式,直接用前面的表达式.所以for语句的完整是for (i=limit; i=0; i--)
		cout << "i = " << i << "\n";//0就是false;for (i=limit; i=false; i--)  i为false时结束循环
	cout << "Done now that i = " << i << "\n";//只要测试表达式值为0（false），循环就结束
	cin.get();
	cin.get();
	return 0;
}
