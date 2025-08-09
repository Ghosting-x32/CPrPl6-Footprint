#include"store.h"

Store::Store(std::ostream& o)
:os(o)
{


}


void Store::operator()(const string& str1)
{
	size_t len = str1.size();
	os.write(reinterpret_cast<const char*>(&len), sizeof(size_t));//��д�ַ���������д�ַ������ݷ����ȡ
	os.write(str1.data(), len);

}

