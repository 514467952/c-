#include<iostream>

using namespace std;

class MyClass
{
public:
	MyClass()
	{
		cout << "Ĭ�ϵĹ��캯��" << endl;

	}

	MyClass(int a)
	{
		cout << "�вι��캯��" << endl;
	}

	int m_A;


};

//ϵͳĬ�ϸ�һ�����ṩ3������ Ĭ�Ϲ��� ���������죬��������


//1 �������ṩ���вι��캯������ôϵͳ�����ٸ������ṩĬ�ϵĹ��캯��
//���� ϵͳ�����ṩĬ�ϵĿ������캯��  ���м򵥵�ֵ����

void test01()
{
	MyClass c1;
	c1.m_A = 10;
	MyClass c2(c1);
	cout << c2.m_A << endl;

}

//�������ṩ�˿������죬��ôϵͳ�����ṩ��������
class MyClass2
{
public:
	/*MyClass2()
	{
		cout << "Ĭ�ϵĹ��캯��" << endl;

	}

	MyClass2(int a)
	{
		cout << "�вι��캯��" << endl;
	}*/

	MyClass2(const MyClass2 &m)
	{

	}

	int m_A;

};

void test02()
{
	MyClass2 c1;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
