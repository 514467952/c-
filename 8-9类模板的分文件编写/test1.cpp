#include<iostream>
#include"Person.hpp"
using namespace std;

//����ģ�岻Ҫ���ļ���д��д��һ���ļ���

//���ڽ������������Ѻ�׺����Ϊ.hppԼ���׳�


int main()
{
	Person<string, int >p("��˽�", 10);
	p.showPerson();


	system("pause");
	return 0;
}

