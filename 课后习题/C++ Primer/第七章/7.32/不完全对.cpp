
/*
要想让clear 函数作为Screen 的友元，只需要在Screen 类中做出友元声明
即可。本题的真正关键之处是程序的组织结构，我们必须首先定义Window_mgr 类，
其中声明clear 函数，但是不能定义它；接下来定义Screen 类，并且在其中指明
clear 函数是其友元；最后定义clear 函数。满足题意的程序如下所示：


两个类的各项排列顺序必须严格如此：

*/


#include <iostream>
#include <string>
using namespace std;

//class Screen;//向前声明
class Window_mgr//如若在这个类面使用了Screen类的对象，遵循不完全类型使用情景，还需向前声明
{
public:
	void clear();
};
class Screen
{
	friend void Window_mgr::clear();
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default; // 默认构造函数
	Screen(unsigned ht, unsigned wd, char c)
		: height(ht), width(wd), contents(ht* wd, c) {
	}
};
void Window_mgr::clear()
{
	Screen myScreen(10, 20, 'X');
	cout << "清理之前myScreen 的内容是：" << endl;
	cout << myScreen.contents << endl;
	myScreen.contents = "";
	cout << "清理之后myScreen 的内容是：" << endl;
	cout << myScreen.contents << endl;
}
int main()
{
	Window_mgr w;
	w.clear();
	return 0;
}