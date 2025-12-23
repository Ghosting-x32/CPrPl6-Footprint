#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;



string::size_type find_char(const string& s, char c, string::size_type &occurs);




int main()
{
	string str1 = "abcdefccccfff";
	string::size_type str = 0;
	string::size_type index = find_char(str1, 'c', str);

	cout << "字符c第一次出现的位置: " << index << "\n字符c出现的次数: " << str << endl;


	system("pause");
	return 0;
}



string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i)
	{
		if (s[i] == 'c')
		{
			if (ret == s.size())
			{
				ret = i;
			}

			++occurs;
		}
	}

	return ret;


}
