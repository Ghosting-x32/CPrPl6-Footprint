#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>







using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::count;








int main()
{
	vector<int> v1(10, 20);
	v1.push_back(63);
	auto sum = count(v1.begin(), v1.end(), 20);
	cout << "容器中共有: " << v1.size() << " 个元素!" << endl;
	cout << "20的个数是: ";
	cout << sum << endl;





	system("pause");
	return 0;
}


	















