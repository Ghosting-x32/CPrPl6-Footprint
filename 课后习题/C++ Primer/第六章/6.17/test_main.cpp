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


bool isUpper_string(const string& str);
void toLower_string(string& str1);





int main()
{

	/*
	第一个函数的任务是判断string 对象中是否含有大写字母，无须修改参数的
内容，因此将其设为常量引用类型。第二个函数需要修改参数的内容，所以应该将
其设定为非常量引用类型。
	
	*/
	string s1 = "abdfHjHHjkKl";
	string s2 = "abfhjhjhjkj";


	cout << s1 << endl;
	if (isUpper_string(s1))
	{
		cout << "有大写字母!" << endl;
	}
	else
	{
		cout << "没有大写字母!" << endl;
	}



	toLower_string(s1);

	cout << s1 << endl;










	system("pause");
	return 0;
}


bool isUpper_string(const string& str)
{
	bool temp = false;
	for (decltype(str.size()) c = 0; c != str.size(); ++c)
	{
		if (!temp)
		{
			temp = isupper(str[c]);
		}
		
	}


	return temp;
}

void toLower_string(string& str1)
{

	for (auto& c : str1)
	{
		c = tolower(c);
	}

}