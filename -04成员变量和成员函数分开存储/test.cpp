

#include<iostream>

using namespace std;

#pragma pack(1)

class Person
{
public:
	int m_A;//�Ǿ�̬��Ա���������ڶ�����

	void func(/*Person * this*/){}; //�Ǿ�̬��Ա���� �����ڶ�������

	static int  m_B;//��̬��Ա�����������ڶ�����

	static void fun2(){};//��̬��Ա���� �������ڶ�������

	//double m_C;//12���� 16��ȷ,�������#pragma pack(1)
};

//���ۣ��Ǿ�̬��Ա�����������ڶ�������

void test01()
{
	cout << "Person��Ĵ�С��" << sizeof(Person) << endl;
	//����Ĵ�СΪ1 ÿ��ʵ���Ķ��� ���ж�һ�޶��ĵ�ַ��charά�������ַ
	//Person p[10] p[0] p[1]
}

void test02()
{

	//thisָ��ָ�򱻵��õĳ�Ա����
	Person p1;
	p1.func(); //��������͵͵ ����һ��thisָ�� Person * this 

	Person p2;
	p2.func();
}

int main()
{
	test01();
	system("pause");
	return 0;
}