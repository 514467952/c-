

#include<iostream>

using namespace std;

class MyString
{
public:

	MyString( string str)
	{
		//
	}
	explicit MyString(int a)
	{
		mSize = a;
	}


	char *mStr;
	int mSize;
};

void test01()
{
	MyString str = "abc";
	//MyString str2 = 10;//��ʲô��;��str2�ַ���Ϊ"10"�ַ����ĳ���10
	//��ʽ����ת��
	MyString str3(10);
	//explicit �ؼ��� ����ֹ��ʽ����ת��
}

int main()
{

	test01();
	system("pause");
	return 0;
}