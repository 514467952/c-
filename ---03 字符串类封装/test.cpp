

#include<iostream>

#include"MyString.h"
using namespace std;

void test01()
{
	MyString str = "abc";

	cout << str << endl;
	/*
		cout << "请输入str新的内容" << endl;
		cin >> str;
		cout << "新内容为" << str<<endl;

		*/
	MyString str2(str);

	MyString str3 = "aaaaaaaaa";
	str3 = str2;
	str3 = "aaaa";

	cout << "str3=" << str3 << endl;

	str3[0] = 'w';

	cout << "str3第一个位置为" << str3[0] << endl;

	MyString str4 (" ");
	str4 = str + str3;//字符串拼接

	cout << "str4为" << str4 << endl;

	/*if (str3 == str4)
	{
	cout << "str3与str4相等" << endl;
	}
	else
	{
	cout << "str3与str4不相等" << endl;
	}
	*/
}

int main()
{

	test01();
	system("pause");
	return 0;
}
