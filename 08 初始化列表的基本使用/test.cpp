#include<iostream>

using namespace std;

class Person
{
public:
	//Ĭ�ϵĹ���
	//Person(){}

		//�вι����ʼ������
		/*Person(int a, int b, int c)
		{
			m_A = a;
			m_B = b;
			m_C = c;
		}
	*/
	//Ĭ�ϵĹ��캯���ĳ�ʼ��
	Person() :m_A(10), m_B(20), m_C(30)
	{}


	//���ó�ʼ���б�����ʼ������
	//���캯������ + : ���ԣ������������ԣ�������....
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{}
		int m_A;
		int m_B;
		int m_C;

};

void test01()
{
	Person p1(10, 20, 30);

	cout << "p1��m_A:" << p1.m_A << endl;
	cout << "p1��m_B:" << p1.m_B<< endl;
	cout << "p1��m_C:" << p1.m_C << endl;

	Person p2;
	cout << "p2��m_A:" << p2.m_A << endl;
	cout << "p2��m_B:" << p2.m_B << endl;
	cout << "p2��m_C:" << p2.m_C << endl;
}

int main()
{


	test01();
	system("pause");
	return 0;
}