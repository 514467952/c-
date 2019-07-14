
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Person
{

public:
	Person()
	{

	}
	//��ʼ������
	Person(char *name, int age)
	{
		m_Name = (char *)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
	}
	//�������� ϵͳ���ṩĬ��
	//�Լ��ṩ�������죬ԭ��򵥵�ǳ�������ͷŶѿռ�����

	Person(const Person&p)
	{
		m_age = p.m_age;
		m_Name = (char *)malloc(strlen(p.m_Name)+1);
		strcpy(m_Name, p.m_Name);
	}

	~Person()
	{
		cout << "���������ĵ���" << endl;
		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}


	//����
	char * m_Name;
	//����
	int m_age;


};

void test01()
{
	Person p1("�з�", 10);
	Person p2(p1);//���ÿ�������
}

int main()
{
	test01();
	system("pause");
	return 0;
}
