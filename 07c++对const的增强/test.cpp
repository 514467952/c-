#include<iostream>


using namespace std;

const int m_a = 10;  //��ȫ��������ܵ������������Ա�����



/*c�����У�const���εı�������α�������������ǻ�����ڴ�ġ�
	c++�У�const��������ڴ棬const int m_B=20;


*/
void test07()
{

	//m_a = 100;   �������޸�
	
	const int m_B = 20;
	//m_B = 100;	�������޸�

	int *p = (int *)&m_B;//*pָ�������ʱ���ǿ�ռ䣬��ʱ�ռ俴����,��ʱ�Ŀռ䱻���ģ���m_Bû�б���

	*p = 200;

	printf("*p=%d,m_B=%d\n", *p, m_B);
	//c��*p ��m_B����200
	//c++��m_BΪ20��û�б�����
}

int main()
{
	test07();
	system("pause");
}
