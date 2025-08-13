#include <iostream>
#include <string>
#include"boost/lexical_cast.hpp"//安装boost库后，需要在解决方案工程文件右键属性-> c/c++ -> 常规 -> 附加包含目录 -> D:\local\boost_1_88_0（boost库的安装目录），配置boost库

using namespace std;

int main() 
{
    cout << "Enter your weight: ";
    float weight;
    cin >> weight;
    string gain = "A 10% increase raises ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " to ";
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;






    system("pause");
    return 0;
}