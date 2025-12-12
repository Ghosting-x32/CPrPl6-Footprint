#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	vector<int> v(10, 0);

	v[3] = -9;
	auto pbeg = v.begin();

	while (pbeg != v.end() && *pbeg >= 0)
	{
		cout << *pbeg++ << " ";//++返回初始的pbeg给*解引用，并将pbeg向后移动一个位置
		//如果是：*++pbeg的话，++则是返回将pbeg向后移动一个位置之后的pbeg给*解引用---这样在这个场景中显然不对
	}
	cout << endl;


	system("pause");
	return 0;
}