#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>//提供size_t
#include<algorithm>
#include<numeric>//提供算术的算法
#include<functional>//提供bind（多元谓词与一元谓词的转换）
#include<fstream>
#include<utility>//提供pair
#include<map>
#include<set>
#include<cctype>







using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::map;
using std::set;









int main()
{
	
	map<string, vector<string>> ma_vestr;

	string fir_na;
	string ls_chna;
	cout << "开始添加家庭！" << endl;
	while (cin >> fir_na)
	{
		ma_vestr[fir_na];
		cout << "开始添加孩子" << endl;

		while (cin >> ls_chna)
		{
			ma_vestr[fir_na].push_back(ls_chna);
		}

		if (!cin)
		{
			cin.clear();
		}
		cout << "添加下一个家庭！" << endl;
	}
	
	for (const auto& c : ma_vestr)
	{
		cout << c.first << "\n";
		for (const auto& d : c.second)
		{
			cout << d << " ";
		}
		cout << endl;
		cout << endl;


	}















	cout << endl;
	system("pause");
	return 0;
}



