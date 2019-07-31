
#include<iostream>
#include<string>
using namespace std;
#include<stdexcept>




void test01()
{
	string str;//默认构造
	string str2(str);//拷贝构造
	string str3 = str;

	string str4 = "abcd";
	string str5(10, 'a');

	cout << str4 << endl;
	cout << str5 << endl;

	//基本赋值
	str = "hello";
	str2 = str4;

	//string &assign(const char *s,int n)//把字符串s的前n个字符赋给当前的字符串
	str3.assign("abcdef", 4);
	cout << str3 << endl;

	//string &assign(const string *s,int start,int n)//将s从start开始n个字符赋值给字符串
	string str6;
	str6.assign(str, 1, 3);//ell ? hel 从0索引

	cout << str6 << endl;

}


void test02()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); i++)
	{
		//cout << s[i] << endl;
		cout << s.at(i) << endl;
	}
	//[]和at区别？[]访问越界，直接挂掉 at会抛出异常

	try
	{
		//cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "越界异常" << endl;
		
	}
}


void test03()
{
	//拼接
	string s1 = "我";
	string s2 = "爱北京";
	s1+=s2;
	cout << s1<< endl;
	s1.append("天安门");
	cout << s1 << endl;

	//find查找
	string s = "abcdefg";
	int pos = s.find("bcf");//找不到返回-1

	cout << "pos=" << pos << endl;

	int pos2 = s.rfind("bc");//rfind和find结果一样，内部查找方式不一样
	cout << "pos2=" << pos2 << endl;

	//替换
	string s3 = "hello";
	s3.replace(1, 3, "1111");//替换从pos开始n个字符为字符串str
	cout << s3 << endl;	//he1111o
}

void test04()
{
	string s1 = "bbc";
	string s2 = "abc";
	if (s1.compare(s2) == 0)
	{
		cout << "s1等于s2" << endl;
	}
	else if (s1.compare(s2)==1)
	{
		cout << "s1大于s2" << endl;
	}
	else
	{
		cout << "s1小于s2" << endl;
	}
}

void test05()
{
	string s1 = "abcde";
	string s2 = s1.substr(1, 3);
	cout <<"s2="<< s2 << endl;

	//需求，查找一个邮件的用户名
	string email = "zhangtao@sina.com";

	int pos=email.find("@");//
	cout << "pos" << pos << endl;

	string userName = email.substr(0, pos);
	cout << "用户名" << userName << endl;

}

void test06()
{
	string s1 = "hello";
	s1.insert(1, "111");
	cout << s1 << endl;//h111ello
	//删除111
	s1.erase(1, 3);
	cout << s1 << endl;
}

/*
string和c-style字符串转换
*/

void func(string s)
{
	cout << s << endl;
}

void func2(char *s)
{
	cout << s << endl;
}
void test07()
{
	string s = "abc";
	//string->char *

	const char *p = s.c_str();
	func(p);//const char *隐式类型转换为string

	//const char *->string 
	string s2(p);
	//func2(s2);//string 不能隐式类型转换成char *

}
void test08()
{
	string s = "abcdefg";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';
	cout << s << endl;
	cout << (int *)s.c_str() << endl;

	s = "pppppppppppppppp";
	/*a='1';
	b = '2';*/
	cout << s << endl;
	cout << (int *)s.c_str() << endl;
}

/*
写一个函数，函数内部string字符串中的所有小写字母都变成大写字母

*/
void test09()
{
	string s = "abCdEfg";

	for (int i = 0; i < s.size(); i++)
	{
		//s[i] = toupper(s[i]); 
		//全变小写
		s[i] = tolower(s[i]);
	}
	cout << s << endl;

}

int main()
{

	//test01();
	//test02();
	//test03();
	///test04();
	//test05();
	///test06();
	//test07();
	//test08();
	test09();
	system("pause");
	return 0;
}