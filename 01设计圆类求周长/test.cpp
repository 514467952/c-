#include<iostream>

using namespace std;

const double pi = 3.14;

//���Բ�࣬��Բ���ܳ�
//�ܳ���ʽ 2*pi*r

class Circle
{
public:  //����Ȩ��

	//��Բ���ܳ�
	//��������д��������Ա����
	double calculateZC()
	{
		return 2*pi*m_R;
	}

	//���ð뾶�ĳ�Ա����
	//��Ա�����������޸ĳ�Ա����
	void setR(int r)
	{
		m_R = r;
	}


	//�뾶  ��Ա����
	int m_R;
};

void test01()
{
	//ͨ���ഴ��Բ
	Circle cl;//Բ ����
	//cl.m_R = 10;//��������������а뾶�ĸ�ֵ
	//ͨ����Ա������������ð뾶
	cl.setR(10);
	//���cl���ܳ�
	cout << "c1���ܳ�" << cl.calculateZC() << endl;
}

int main()
{

	test01();
	system("pause");
	return 0;
}