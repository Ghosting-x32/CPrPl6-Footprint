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
#include<list>
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
using std::list;
using std::pair;







int main()
{
	map<string, vector<string>> ma_vestr;
	vector<pair<string, string>> ve_brAndlas;

	string fir_na;
	string ls_chna;
	string br_aa;
	cout << "开始添加家庭！" << endl;
	while (cin >> fir_na)
	{
		ma_vestr[fir_na];
		cout << "开始添加孩子和孩子的生日" << endl;

		while (cin >> ls_chna >> br_aa)
		{
			ma_vestr[fir_na].push_back(ls_chna);
			ve_brAndlas.push_back(std::make_pair(ls_chna, br_aa));
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

	for (const auto& c : ve_brAndlas)
	{
		cout << c.first << "\t" << c.second << endl;
	}
	
	cout << endl;















	cout << endl;
	system("pause");
	return 0;
}



