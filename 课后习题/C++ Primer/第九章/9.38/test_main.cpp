#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>





using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::list;
using std::deque;
using std::forward_list;







int main()
{
	vector<int> vi;
	int s, c;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数：" << vi.size() << endl;


	system("pause");
	return 0;
}








