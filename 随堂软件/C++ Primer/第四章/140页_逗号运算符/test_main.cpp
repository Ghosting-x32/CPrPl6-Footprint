#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>    
#include<climits>
#include<limits>




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
using std::numeric_limits;




int main()
{
	vector<int> ivec(10, 0);
	vector<int>::size_type cnt = ivec.size();
	for (auto& c : ivec)
	{
		cout << c << " ";
	}
	cout << endl;

	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
	{
		ivec[ix] = cnt;
	}

	for (auto& c : ivec)
	{
		cout << c << " ";
	}
	cout << endl;





	system("pause");
	return 0;
}