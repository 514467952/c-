#include<iostream>

using namespace std;



class Person
{
public:
	Person()
	{
		//m_Age = 10;
	}


	static int m_Age;//����static ��̬��Ա�������Ṳ������
	//��̬��Ա���������������������ʼ��
	int m_A;

	//��̬��Ա����
	//1.�����Է���  ��ͨ�ĳ�Ա����
	//2.���Է���	��̬��Ա����
	//3.��̬��Ա����Ҳ����Ȩ�޵�
	static void func()
	{
		//m_A = 10;
		m_Age = 100;
		cout << "func����" << endl;
	}

	//��ͨ��Ա���������Է�����ͨ��Ա������Ҳ���Է��ʾ�̬��Ա����

	void myFunc()
	{
		m_A = 10;
		m_Age = 100;
	}

private:
	static int m_other;//˽��Ȩ�ޣ����ⲻ�ܷ���

	static void func2()
	{
		cout << "func2����" << endl;
	}

};

int Person::m_other = 0;

int Person::m_Age = 0;//�����ʼ��


void test01()
{
	//1.ͨ�������������
	Person p1;
	p1.m_Age = 10;

	Person p2;
	p2.m_Age = 20;

	cout << "p1=" << p1.m_Age << endl;
	cout << "p2=" << p2.m_Age << endl;
	//�������ݣ�����20�������һ�θ�ֵΪ׼

	//2.ͨ��������������
	//��Ϊͨ���������ʣ����Բ��������ڳ�ʼ��
	cout << "ͨ����������Age" << Person::m_Age << endl;

	//cout << "other=" << Person::m_other << endl;//˽��Ȩ���������޷�����

	//��̬��Ա��������
	//�����Է��� ��ͨ�ĳ�Ա����
	p1.func();
	p2.func();
	Person::func();

	//Person::func2();//��̬��Ա������Ϊ˽�У����ⲻ�ܷ���
}




int main()
{

	test01();
	system("pause");
	return 0;
}