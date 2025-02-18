#include <iostream>
int main()
{
	using namespace std;              //A代表long,B代表码。
	cout << "请输入需转换的长度：";
	int A;
	cin >> A;
	int B;
	B = A * 220;
	cout << A << " long = " << B << " 码";
	cin.get();
	cin.get();
	return 0;
}