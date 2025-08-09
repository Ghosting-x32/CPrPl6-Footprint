#include<iostream>
#include<cstdlib>


using namespace std;



int main()
{
	
	cout << "This system can generate up to " << TMP_MAX
		<< " temporary name of up to " << L_tmpnam
		<< " character.\n";

	char pszName[L_tmpnam] = { '\0' };
	cout << "Here are ten names:\n";
	for (int i = 0; 10 > i; i++)
	{
		tmpnam_s(pszName);
		cout << pszName << endl;


	}









	system("pause");
	return 0;
}