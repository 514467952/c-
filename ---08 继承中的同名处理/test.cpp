
#include<iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void fun()
	{
		cout << "Base func�ĵ���" << endl;
	}
	void fun(int a)
	{
		cout << "Base func(int a)�ĵ���" << endl;
	}
	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void fun()
	{
		cout << "Son func�ĵ���" << endl;
	}

	int m_A;
};

void test01()
{
	Son s1;
	cout << s1.m_A << endl;

	//����� �����е�m_A
	cout << s1.Base::m_A << endl;

	//s1.fun(10);

	//���ø����func
	s1.Base::fun();
}
//������������ӵ��ͬ���ĺ��� ���� ���಻�Ḳ�Ǹ����Ա
//��������븸��ĳ�Ա����������ͬ �����Ѹ��������ͬ���汾�����ص�
//����ø���ķ����������������

int main()
{
	test01();
	system("pause");
	return 0;
}