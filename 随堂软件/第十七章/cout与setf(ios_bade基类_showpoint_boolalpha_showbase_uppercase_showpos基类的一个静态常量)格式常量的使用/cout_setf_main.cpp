#include<iostream>
#include<string>


using namespace std;

int main()
{
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);//������ǰ�����+
	cout << temperature << endl;
	
	cout << "For out programming friends, that's\n";
	cout << hex << temperature << endl;//16����
	cout.setf(ios_base::uppercase);//����16���������ʹ�ô�д��ĸ
	cout.setf(ios_base::showbase);//���������ʹ��C++����ǰ׺��0�� 0x��
	cout << "or\n";
	cout << temperature << endl;

	cout << "How " << true << "! oops -- How ";
	cout.setf(ios_base::boolalpha);//��������boolֵ������Ϊtrue��false
	cout << true << "!\n";












	system("pause");
	return 0;
}