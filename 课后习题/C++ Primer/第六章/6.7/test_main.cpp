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




size_t myADD();


int main()
{

	
	for (size_t i = 0; i != 10; ++i)
	{
		cout << "函数myADD被调用后的返回值是: " << myADD() << "\n";
	}
	cout << endl;


	system("pause");
	return 0;
}



size_t myADD() 
{
	
	static unsigned iCnt = 0;
	
	
	return iCnt++;
}