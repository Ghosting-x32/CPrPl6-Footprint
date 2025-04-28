#include<iostream>
#include<string>

using namespace std;

void change(const int* pt, int n);

int main()
{
	int pop1 = 38383;
	const int pop5 = 3000;//解const若pt指向的变量是一个const变量，那还是不能修改该变量的值
	const int pop2 = 2000;
	const int* pop4 = &pop5;//
	int* pop6 = const_cast<int*>(pop4);
	cout << "pop5, pop4, pop6: " << pop5 << ", " << *pop4 << ", " << *pop6 << endl;	
	*pop6 = 3692;
	cout << "pop5, pop4, pop6: " << pop5 << ", " << *pop4 << ", " << *pop6 << endl;
	
	int* pop3 = const_cast<int*>(&pop2);//解const若pt指向的变量是一个const变量，那还是不能修改该变量的值

	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	change(pop3, -103);


	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;
	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;

	*pop3 = 8965;
	cout << "pop1, pop2, pop3: " << pop1 << ", " << pop2 << ", " << *pop3 << endl;
	//总结：const_cast只能解指针类型的const，解不了非指针类型的const
	system("pause");
	return 0;
}


void change(const int* pt, int n)
{
	int* pc;
	
	pc = const_cast<int*>(pt);//解const若pt指向的变量是一个const变量，那还是不能修改该变量的值
	*pc += n;
	


}