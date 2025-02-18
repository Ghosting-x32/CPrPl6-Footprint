#include<iostream>
#include"cow.h"


int main()
{
    Cow cow1;
    cow1.ShowCow();

    Cow cow2("guxu", "lanqiu", 60);
    cow2.ShowCow();

    Cow cow3 = cow2;
    cow3.ShowCow();

    cow1 = cow2;
    cow1.ShowCow();


    system("pause");
    return 0;
}