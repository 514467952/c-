

#include<iostream>

#include"MyString.h"
using namespace std;

void test01()
{
	MyString str = "abc";

	cout << str << endl;
	/*
		cout << "������str�µ�����" << endl;
		cin >> str;
		cout << "������Ϊ" << str<<endl;

		*/
	MyString str2(str);

	MyString str3 = "aaaaaaaaa";
	str3 = str2;
	str3 = "aaaa";

	cout << "str3=" << str3 << endl;

	str3[0] = 'w';

	cout << "str3��һ��λ��Ϊ" << str3[0] << endl;

	MyString str4 (" ");
	str4 = str + str3;//�ַ���ƴ��

	cout << "str4Ϊ" << str4 << endl;

	/*if (str3 == str4)
	{
	cout << "str3��str4���" << endl;
	}
	else
	{
	cout << "str3��str4�����" << endl;
	}
	*/
}

int main()
{

	test01();
	system("pause");
	return 0;
}
