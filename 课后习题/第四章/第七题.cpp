#include <iostream>
#include<string>
using namespace std;
struct William
{
	string gsi;
	double zj;
	double zl;
};
int main()
{
	William ps;
	cout << "请输入披萨公司名称：";
	getline(cin, ps.gsi);
	cout << "请输入披萨的直径：";
	cin >> ps.zj;
	cout << "请输入披萨的重量：";
	cin >> ps.zl;
	cout << endl;
	cout << "你的披萨(ps)的数据如下：\n";
	cout << "ps公司名称：" << ps.gsi << endl;
	cout << "ps直径：" << ps.zj << endl;
	cout << "ps重量：" << ps.zl << endl;
	cin.get();
	cin.get();
	return 0;
}
