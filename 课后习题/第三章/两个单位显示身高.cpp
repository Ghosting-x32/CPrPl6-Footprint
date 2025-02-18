#include <iostream>
int main()
{
	using namespace std;
	const int Asg = 100;
	int lmi;
	cout << "请输入你以厘米为单位的身高数值：___\b\b\b";
	cin >> lmi;
	int mi = lmi / Asg;
	int sy = lmi % Asg;
	cout << "你的身高是：" << mi << "米" << sy << "厘米.";
	cin.get();
	cin.get();
	return 0;
}
