#include <iostream>
#include <regex>
#include <string>

int main() 
{
    //������ʽ��ȡ�����ַ
    std::string text = "Contact us at email@example.com or support@company.org";
    std::regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");//�����������Ӵ�

    // ��������ƥ��
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = std::sregex_iterator();

    std::cout << "Found " << std::distance(words_begin, words_end) << " emails:\n";//��������������ж��ٸ�Ԫ��

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;//��������������Ӵ�
        std::cout << match.str() << '\n';//ת��Ϊc����ַ���
    }

    // �滻����
    std::string result = std::regex_replace(text, pattern, "[EMAIL REDACTED]");//�滻������text���е��Ӵ�(pattern)��ͨ���ṩ���ַ���
    std::cout << "\nRedacted text:\n" << result << std::endl;

    system("pause");
    return 0;
}