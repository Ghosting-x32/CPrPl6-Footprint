#include<iostream>
#include<string>

using namespace std;

void change(const int* pt, int n);

int main()
{
	int pop1 = 38383;
	const int pop5 = 3000;//��const��ptָ��ı�����һ��const�������ǻ��ǲ����޸ĸñ�����ֵ
	const int pop2 = 2000;
	const int* pop4 = &pop5;//
	int* pop6 = const_cast<int*>(pop4);
	cout << "pop5, pop4, pop6: " << pop5 << ", " << *pop4 << ", " << *pop6 << endl;	
	*pop6 = 3692;
	cout << "pop5, pop4, pop6: " << pop5 << ", " << *pop4 << ", " << *pop6 << endl;
	
	int* pop3 = const_cast<int*>(&pop2);//��const��ptָ��ı�����һ��const�������ǻ��ǲ����޸ĸñ�����ֵ

	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	change(pop3, -103);


	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;
	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;

	*pop3 = 8965;
	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;
	//�ܽ᣺const_castֻ�ܽ�ָ�����͵�const���ⲻ�˷�ָ�����͵�const
	system("pause");
	return 0;
}


void change(const int* pt, int n)
{
	int* pc;
	
	pc = const_cast<int*>(pt);//��const��ptָ��ı�����һ��const�������ǻ��ǲ����޸ĸñ�����ֵ
	*pc += n;
	


}