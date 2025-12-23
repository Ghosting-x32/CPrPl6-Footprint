#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;








int main(int argc, char* argv[])
{
	
	string str;
	for (size_t i = 0; i < argc; ++i)
	{
		str += argv[i];
		cout << argv[i] << endl;

	}

	cout << "**************************************" << endl;
	cout << str << endl;




	system("pause");
	return 0;
}


