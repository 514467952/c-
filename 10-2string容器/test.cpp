
#include<iostream>
#include<string>
using namespace std;
#include<stdexcept>




void test01()
{
	string str;//Ĭ�Ϲ���
	string str2(str);//��������
	string str3 = str;

	string str4 = "abcd";
	string str5(10, 'a');

	cout << str4 << endl;
	cout << str5 << endl;

	//������ֵ
	str = "hello";
	str2 = str4;

	//string &assign(const char *s,int n)//���ַ���s��ǰn���ַ�������ǰ���ַ���
	str3.assign("abcdef", 4);
	cout << str3 << endl;

	//string &assign(const string *s,int start,int n)//��s��start��ʼn���ַ���ֵ���ַ���
	string str6;
	str6.assign(str, 1, 3);//ell ? hel ��0����

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
	//[]��at����[]����Խ�磬ֱ�ӹҵ� at���׳��쳣

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
		cout << "Խ���쳣" << endl;
		
	}
}


void test03()
{
	//ƴ��
	string s1 = "��";
	string s2 = "������";
	s1+=s2;
	cout << s1<< endl;
	s1.append("�찲��");
	cout << s1 << endl;

	//find����
	string s = "abcdefg";
	int pos = s.find("bcf");//�Ҳ�������-1

	cout << "pos=" << pos << endl;

	int pos2 = s.rfind("bc");//rfind��find���һ�����ڲ����ҷ�ʽ��һ��
	cout << "pos2=" << pos2 << endl;

	//�滻
	string s3 = "hello";
	s3.replace(1, 3, "1111");//�滻��pos��ʼn���ַ�Ϊ�ַ���str
	cout << s3 << endl;	//he1111o
}

void test04()
{
	string s1 = "bbc";
	string s2 = "abc";
	if (s1.compare(s2) == 0)
	{
		cout << "s1����s2" << endl;
	}
	else if (s1.compare(s2)==1)
	{
		cout << "s1����s2" << endl;
	}
	else
	{
		cout << "s1С��s2" << endl;
	}
}

void test05()
{
	string s1 = "abcde";
	string s2 = s1.substr(1, 3);
	cout <<"s2="<< s2 << endl;

	//���󣬲���һ���ʼ����û���
	string email = "zhangtao@sina.com";

	int pos=email.find("@");//
	cout << "pos" << pos << endl;

	string userName = email.substr(0, pos);
	cout << "�û���" << userName << endl;

}

void test06()
{
	string s1 = "hello";
	s1.insert(1, "111");
	cout << s1 << endl;//h111ello
	//ɾ��111
	s1.erase(1, 3);
	cout << s1 << endl;
}

/*
string��c-style�ַ���ת��
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
	func(p);//const char *��ʽ����ת��Ϊstring

	//const char *->string 
	string s2(p);
	//func2(s2);//string ������ʽ����ת����char *

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
дһ�������������ڲ�string�ַ����е�����Сд��ĸ����ɴ�д��ĸ

*/
void test09()
{
	string s = "abCdEfg";

	for (int i = 0; i < s.size(); i++)
	{
		//s[i] = toupper(s[i]); 
		//ȫ��Сд
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