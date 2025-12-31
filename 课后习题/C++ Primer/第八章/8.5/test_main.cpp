#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>
#include<fstream>







using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;




void fget_vcstr(std::ifstream& input, vector<string>& vv);



int main()
{
	std::ifstream Input("ccc.txt");

	vector<string> v1;

	fget_vcstr(Input, v1);

	for (auto& c : v1)
	{
		cout << c << "\t";
	}

	cout << endl;

	system("pause");
	return 0;
}


void fget_vcstr(std::ifstream& input, vector<string>& vv)
{
	string temp;

	while (input >> temp)
	{
		vv.push_back(temp);
	}

}





