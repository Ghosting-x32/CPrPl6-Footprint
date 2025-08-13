#include <iostream>
#include <regex>
#include <string>

int main() 
{
    //正则表达式提取邮箱地址
    std::string text = "Contact us at email@example.com or support@company.org";
    std::regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");//符合条件的子串

    // 查找所有匹配
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = std::sregex_iterator();

    std::cout << "Found " << std::distance(words_begin, words_end) << " emails:\n";//计算迭代器区间有多少个元素

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;//储存符合条件的子串
        std::cout << match.str() << '\n';//转换为c风格字符串
    }

    // 替换操作
    std::string result = std::regex_replace(text, pattern, "[EMAIL REDACTED]");//替换父串（text）中的子串(pattern)，通过提供的字符串
    std::cout << "\nRedacted text:\n" << result << std::endl;

    system("pause");
    return 0;
}